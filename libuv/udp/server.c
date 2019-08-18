#include<uv.h>
#include<stdio.h>

uv_loop_t* loop;
uv_udp_send_t req;
uv_udp_t server;
struct sockaddr_in addr_info;

static void send_cb(
  uv_udp_send_t* req,
  int status
) {
  printf("send response status: %d\n", status);
}

void recv_cb(
  uv_udp_t* handle,
  ssize_t nread,
  const uv_buf_t* buf,
  const struct sockaddr* addr,
  unsigned flags
) {
  printf("receive: %s, length: %zu.\n", buf->base, buf->len);

  uv_udp_send_t* req;
  // send pong
  uv_udp_recv_stop(handle);
  req = malloc(sizeof *req);
  
  uv_buf_t pong_buf = uv_buf_init("PONG", 4);
  int ok = uv_udp_send(
    &req,
    handle,
    &pong_buf,
    1,
    addr,
    send_cb
  );

  if (ok != 0)
  {
    printf("send pong error: %d, msg: %s\n", ok, uv_strerror(ok));
  }
}

void alloc_cb(
  uv_handle_t* handle,
  size_t suggested_size,
  uv_buf_t* buf
) {
  
}

int main()
{
  loop = uv_default_loop();

  uv_udp_init(loop, &server);
  uv_ip4_addr("0.0.0.0", 7001, &addr_info);
  uv_udp_bind(&server, (const struct sockaddr*) &addr_info, 0);
  int ok = uv_udp_recv_start(&server, alloc_cb, recv_cb);
  printf("listening at: %d, status: %d\n", 7001, ok);

  uv_run(loop, UV_RUN_DEFAULT);
  return 0;
}
