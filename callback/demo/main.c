#include <stdio.h>

typedef void (*callback) (int);

void forEach(int arr[], callback cb) {
  for(size_t i = 0; i < sizeof(&arr); i++)
  {
    (*cb)(arr[i]);
  }
}

void cb(int n) {
  printf("call: %d\n", n * n);
}

int main() {
  int a[10] = {0, 1, 2, 3, 4, 5, 6};
  printf("length of arr: %lu, length of a[0]: %lu\n", sizeof(&a), sizeof(&a[0]));
  forEach(a, &cb);
};
