#include<stdio.h>
#include<stdlib.h>
#include<uv.h>

struct thread_data {
  int start;
  int end;
  int result;
};

static void plus_thread(void* arg) {
  struct thread_data *data = (struct thread_data *)arg;
  data->result = 0;
  for (int i = data->start; i <= data->end; i++) {
    data->result += i;
  }
}

int main() {
  uv_thread_t threads[10];
  struct thread_data dataArray[10];

  for (int i = 0; i < 10; i++) {
    struct thread_data* data = dataArray + i;
    data->start = i * 10 + 1;
    data->end = (i + 1)*10;

    uv_thread_create(threads + i, plus_thread, data);
  }

  int sum = 0;
  for (int i = 0; i < 10; i++) {
    uv_thread_join(threads + i);
    struct thread_data* data = dataArray + i;
    sum += data->result;
  }

  printf("the sum is: %d\n", sum);
  return 0;
}
