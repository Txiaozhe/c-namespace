#include <uv.h>
#include <stdio.h>

int repeat = 0;

void callback(uv_timer_t* handler) {
  repeat++;
  if (repeat == 10) {
    uv_timer_stop(handler);
    uv_close((uv_handle_t*)handler, NULL);
  }
  printf("timer...");
}

int main() {
  uv_loop_t* loop = uv_loop_new();
  uv_timer_t timer;

  int err = uv_timer_init(loop, &timer);

  uv_timer_start(&timer, callback, 1000, 1);

  return uv_run(loop, UV_RUN_DEFAULT);
}
