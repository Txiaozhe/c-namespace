#include <uv.h>
#include <stdio.h>

int repeat = 0;

void callback(uv_timer_t* handler) {
  repeat++;
  if (repeat == 10) {
    uv_timer_stop(handler);
    uv_close((uv_handle_t*)handler, NULL);
  }
  printf("timer...\n");
}

int main() {
  uv_loop_t* loop = uv_loop_new();
  uv_timer_t timer;

  int err = uv_timer_init(loop, &timer);

  uv_timer_start(&timer, callback, 1000, 0); // repeat 为重复执行的间隔时间，为0时不重复

  return uv_run(loop, UV_RUN_DEFAULT);
}
