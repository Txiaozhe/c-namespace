#include <iostream>

static int8_t hex2bin(char c) {
  if (c >= '0' && c <= '9')
    return (int8_t)(c - '0');
  if (c >= 'A' && c <= 'F')
    return (int8_t)(10 + (c - 'A'));
  if (c >= 'a' && c <= 'f')
    return (int8_t)(10 + (c - 'a'));

  return (int8_t)(-1);
}

static size_t hex_decode(char* buf, size_t len, const char* src,
                         const size_t srcLen) {
  size_t i;

  for (i = 0; i < len && i * 2 + 1 < srcLen; ++i) {
    int8_t a = hex2bin(src[i * 2 + 0]);
    int8_t b = hex2bin(src[i * 2 + 1]);

    std::cout << "src1: " << src[i * 2 + 0] << ", a: " << a << std::endl;
    std::cout << "src2: " << src[i * 2 + 1] << ", b: " << b << std::endl;

    if (a == -1 || b == -1)
      return i;
    buf[i] = (a << 4) | b;
  }

  return i;
}

int main() {
    std::string result = "";
    std::string b = "def";
    size_t s = hex_decode((char*)result.data(), 10, (char*)b.data(), 10);
    std::cout << s << ", result: " << result << std::endl;
    return 0;
}
