#include <iostream>

// 捕获外部变量
int main() {
  int a = 123;
  auto f = [a] { std::cout << a << std::endl; };
  f();

  auto x = [](int a) { return a; }(234);
  std::cout << x << std::endl;

  // 值捕获
  int b1 = 222;
  auto v1 = [a]{ std::cout << "值捕获: " << a << std::endl; };
  b1 = 234;
  v1();

  // 引用捕获
  int b2 = 333;
  auto v2 = [&b2] { std::cout << "引用捕获: " << b2 << std::endl; };
  b2 = 444;
  v2();

  // 隐式值捕获
  int b3 = 555;
  auto v3 = [=] { std::cout << "隐式值捕获: " << b3 << std::endl; };
  v3();

  // 隐式引用捕获
  int b4 = 666;
  auto v4 = [&] { std::cout << "隐式引用捕获: " << b4 << std::endl; };
  b4 = 777;
  v4();

  // 修改捕获变量，值传递中不能修改变量，加上mutable关键字就可以
  int b5 = 888;
  auto v5 = [a]()mutable { std::cout << "修改捕获变量, 改变后: " << ++a; };
  std::cout << "修改捕获变量: " << a << std::endl;
  v5();
}
