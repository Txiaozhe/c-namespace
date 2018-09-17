#include <iostream>

size_t ascii_decode(char* buf, size_t len, const char* src,
                           const size_t secLen) {
  size_t i;

  for (i = 0; i < len; ++i) {
      buf[i] = (int) src[i];

      std::cout << (int) src[i] << " ==> " << buf[i] << std::endl;
  }
  return i;
}

int main() {
    std::string result = "";
    std::string b = "defdddds";
    size_t s = ascii_decode((char*)result.data(), 10, (char*)b.data(), 10);

    return 0;
}
