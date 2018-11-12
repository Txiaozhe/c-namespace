#include <iostream>

namespace spc1 {
  void func() {
    std::cout << "From spc1" << std::endl;
  }
}

namespace spc2 {
  void func() {
    std::cout << "From spc2" << std::endl;
  }
}

int main() {
  spc1::func();

  spc2::func();
}
