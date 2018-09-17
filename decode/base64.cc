#include <iostream>

#define base64_encoded_size(size) ((size + 2 - ((size + 2) % 3)) / 3 * 4)

size_t base64_encode(char *const src, size_t slen, char *dst,
                     size_t dlen) {
    dlen = base64_encoded_size(slen);

    unsigned a, b, c, i, k, n;

    static const char table[] = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";
    
    i = 0;
    k = 0;
    n = slen / 3 * 3;

    while (i < n) {
        a = src[i + 0] & 0xff;
        b = src[i + 1] & 0xff;
        c = src[i + 2] & 0xff;

        dst[k + 0] = table[a >> 2];
        dst[k + 1] = table[((a & 3) << 4) | (b >> 4)];
        dst[k + 2] = table[((b & 0x0f) << 2) | (c >> 6)];
        dst[k + 3] = table[c & 0x3f];

        i += 3;
        k += 4;
    };

    if (n != slen) {
        switch(slen - n) {
            case 1:
              a = src[i + 0] & 0xff;
              dst[k + 0] = table[a >> 2];
              dst[k + 1] = table[(a & 3) << 4];
              dst[k + 2] = '=';
              dst[k + 3] = '=';
              break;
            case 2:
              a = src[i + 0] & 0xff;
              b = src[i + 1] & 0xff;
              dst[k + 0] = table[a >> 2];
              dst[k + 1] = table[((a & 3) << 4) | (b >> 4)];
              dst[k + 2] = table[(b & 0x0f) << 2];
              dst[k + 3] = '=';
              break;
        }
    }

    return dlen;
}

int main() {
    std::string src = "dddd";
    std::string dst;
    size_t s = base64_encode((char *)src.data(), 4, (char*)src.data(), 4);
    std::cout << "slen: " << s << std::endl;
    std::cout << "dst: " << dst << std::endl;
}
