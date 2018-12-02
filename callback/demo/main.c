#include <stdio.h>

typedef void (*callback) (int);

void forEach(int arr[], int len, callback cb) {
  // 如果操作数是函数中的数组形参或函数类型的形参，sizeof给出其只针对的大小，所以是8
  for(size_t i = 0; i < len / 4; i++)
  {
    (*cb)(arr[i]);
  }
}

void cb(int n) {
  printf("call: %d\n", n * n);
}

int main() {
  int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("length of arr: %lu, length of a[0]: %lu\n", sizeof(a), sizeof(&a[0])); // 44, 8
  forEach(a, sizeof(a), &cb);
};
