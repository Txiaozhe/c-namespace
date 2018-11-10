#include <iostream>
#include "mymath.h"

using namespace std;

int main() {
  double res1 = f1(1.2);
  double res2 = f2(1.2, 1.3);

  cout << "result==> res1: " << res1 << ", res2: " << res2 << endl;
  return 0;
}
