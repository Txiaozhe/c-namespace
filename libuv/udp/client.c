#include<uv.h>
#include<stdio.h>

void close_cb(uv_udp_send_t* req, int status) {
  printf("uv udp closed: %d\n", status);
}

void recv_cb(
  uv_udp_t* handle,
  ssize_t nread,
  const uv_buf_t* buf,
  const struct sockaddr* addr,
  unsigned flags
) {
  printf("receive response: %s, length: %zu.\n", buf->base, buf->len);
}

void alloc_cb(
  uv_handle_t* handle,
  size_t suggested_size,
  uv_buf_t* buf
) {
  uv_close(handle, close_cb);
}

static void send_cb(
  uv_udp_send_t* req,
  int status
) {
  printf("send status: %d\n", status);
    // listening pong
  int listen_ok = uv_udp_recv_start(req->handle, alloc_cb, recv_cb);
  if (listen_ok != 0) {
    printf("listen status: %d\n", listen_ok);
  }
}

int main()
{
  uv_loop_t* loop = uv_default_loop();
  uv_udp_t client;
  uv_udp_send_t req;
  uv_buf_t buf;
  struct sockaddr_in addr_info;

  // send ping
  uv_ip4_addr("127.0.0.1", 7001, &addr_info);
  uv_udp_init(loop, &client);
  uv_udp_bind(&client, (const struct sockaddr*) &addr_info, 0);
  buf = uv_buf_init("PING", 4);
  printf("will send: %s, length: %zu\n", buf.base, buf.len);
  int ok = uv_udp_send(
    &req,
    &client,
    &buf,
    1,
    (const struct sockaddr*) &addr_info,
    send_cb
  );

  if (ok != 0)
  {
    printf("send error: %d, msg: %s\n", ok, uv_strerror(ok));
  }
  

  uv_run(loop, UV_RUN_DEFAULT);
  return 0;
}
