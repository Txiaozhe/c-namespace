#include <stdio.h>
#include <mbedtls/x509_crl.h>
#include "mbedtls/platform.h"
 
int main()
{
  mbedtls_x509_crl xcrl;
  mbedtls_x509_crl_init(&xcrl);
  int err = mbedtls_x509_crl_parse_file(&xcrl, "/Users/jimtang/GitHub/c-namespace/mbedtls/test_key.pem");
  if (err != 0) {
    mbedtls_printf("failed\n  !  mbedtls_x509_crl_parse_file returned %d\n\n", err);
    mbedtls_x509_crl_free( &xcrl );
  }
  printf("version: %d\n", (&xcrl)->version);

  mbedtls_x509_crl_free (&xcrl);
}
