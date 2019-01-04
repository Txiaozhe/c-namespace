#include <stdio.h>

int main() {
  char list[30];
  FILE *stream;

  stream = fopen("test.file", "r+t");
  if (stream == NULL) {
    printf("file is empty or not exist\n");
    return 0;
  }

  int read = fread(list, sizeof(char), 25, stream);
  fclose(stream);
  printf("read: %d\n", read);
  return 0;
}
