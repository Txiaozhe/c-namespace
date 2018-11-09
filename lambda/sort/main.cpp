#include <iostream>
#include <vector>
#include <algorithm>

// 因为使用了iostream 而非iostream.h，所以必须声明命名空间，或者使用 std::cout 的形式
// using namespace std;

int main() {
  std::vector<int> myvec{ 3, 2, 5, 7, 3, 2 };
  std::vector<int> lbvec(myvec);

  std::sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool { return a < b; });
  std::cout << "lambda expression: " << std::endl;
  for (int it : lbvec) 
    std::cout << it << "  ";
}
