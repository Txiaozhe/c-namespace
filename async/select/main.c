#include<sys/select.h>
#include<sys/time.h>
#include<stdio.h>

int main() {
  fd_set rd;
  struct timeval tv;
  int err;

  FD_ZERO(&rd);
  FD_SET(0, &rd);

  tv.tv_sec = 5;
  tv.tv_usec = 0;
  err = select(1, &rd, NULL, NULL, &tv);

  if (err == 0)
  {
    printf("select timeout\n");
  }
  else if (err == -1) {
    printf("fail to select\n");
  }
  else {
    printf("data is avaliable!\n");
  }

  return 0;
}
