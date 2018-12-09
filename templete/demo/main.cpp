#include <iostream>

template<typename T>
int compare(const T& left, const T& right) {
  if (left < right) {
    return -1;
  }

  if (left > right) {
    return 1;
  }

  return 0;
}

int main() {
  int c = compare<int>(1, 2);
  std::cout << c << std::endl;
}
