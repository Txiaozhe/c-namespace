#include <stdio.h>
#include "mbedtls/x509.h"
#include "mbedtls/platform.h"
#include "mbedtls/ssl.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/platform.h"

static int my_verify( void *data, mbedtls_x509_crt *crt, int depth, uint32_t *flags )
{
    char buf[1024];
    // ((void) data);

    // mbedtls_printf( "\nVerify requested for (Depth %d):\n", depth );
    // mbedtls_x509_crt_info( buf, sizeof( buf ) - 1, "", crt );
    // mbedtls_printf( "%s", buf );

    if ( ( *flags ) == 0 )
        mbedtls_printf( "  This certificate has no flags\n" );
    else
    {
        mbedtls_x509_crt_verify_info( buf, sizeof( buf ), "   ", *flags );
        mbedtls_printf( "%s\n", buf );
    }

    return( 0 );
}

int main()
{
  const char PRIVATE_KEY[] =
    "-----BEGIN RSA PRIVATE KEY-----\n"
    "MIICXQIBAAKBgQDx3wdzpq2rvwm3Ucun1qAD/ClB+wW+RhR1nVix286QvaNqePAd\n"
    "CAwwLL82NqXcVQRbQ4s95splQnwvjgkFdKVXFTjPKKJI5aV3wSRN61EBVPdYpCre\n"
    "535yfG/uDysZFCnVQdnCZ1tnXAR8BirxCNjHqbVyIyBGjsNoNCEPb2R35QIDAQAB\n"
    "AoGBAJNem9C4ftrFNGtQ2DB0Udz7uDuucepkErUy4MbFsc947GfENjDKJXr42Kx0\n"
    "kYx09ImS1vUpeKpH3xiuhwqe7tm4FsCBg4TYqQle14oxxm7TNeBwwGC3OB7hiokb\n"
    "aAjbPZ1hAuNs6ms3Ybvvj6Lmxzx42m8O5DXCG2/f+KMvaNUhAkEA/ekrOsWkNoW9\n"
    "2n3m+msdVuxeek4B87EoTOtzCXb1dybIZUVv4J48VAiM43hhZHWZck2boD/hhwjC\n"
    "M5NWd4oY6QJBAPPcgBVNdNZSZ8hR4ogI4nzwWrQhl9MRbqqtfOn2TK/tjMv10ALg\n"
    "lPmn3SaPSNRPKD2hoLbFuHFERlcS79pbCZ0CQQChX3PuIna/gDitiJ8oQLOg7xEM\n"
    "wk9TRiDK4kl2lnhjhe6PDpaQN4E4F0cTuwqLAoLHtrNWIcOAQvzKMrYdu1MhAkBm\n"
    "Et3qDMnjDAs05lGT72QeN90/mPAcASf5eTTYGahv21cb6IBxM+AnwAPpqAAsHhYR\n"
    "9h13Y7uYbaOjvuF23LRhAkBoI9eaSMn+l81WXOVUHnzh3ZwB4GuTyxMXXNOhuiFd\n"
    "0z4LKAMh99Z4xQmqSoEkXsfM4KPpfhYjF/bwIcP5gOei\n"
    "-----END RSA PRIVATE KEY-----\n";

  const char PUBLIC_KEY[] =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIDXDCCAsWgAwIBAgIJAKL0UG+mRkSPMA0GCSqGSIb3DQEBBQUAMH0xCzAJBgNV\n"
    "BAYTAlVLMRQwEgYDVQQIEwtBY2tuYWNrIEx0ZDETMBEGA1UEBxMKUmh5cyBKb25l\n"
    "czEQMA4GA1UEChMHbm9kZS5qczEdMBsGA1UECxMUVGVzdCBUTFMgQ2VydGlmaWNh\n"
    "dGUxEjAQBgNVBAMTCWxvY2FsaG9zdDAeFw0wOTExMTEwOTUyMjJaFw0yOTExMDYw\n"
    "OTUyMjJaMH0xCzAJBgNVBAYTAlVLMRQwEgYDVQQIEwtBY2tuYWNrIEx0ZDETMBEG\n"
    "A1UEBxMKUmh5cyBKb25lczEQMA4GA1UEChMHbm9kZS5qczEdMBsGA1UECxMUVGVz\n"
    "dCBUTFMgQ2VydGlmaWNhdGUxEjAQBgNVBAMTCWxvY2FsaG9zdDCBnzANBgkqhkiG\n"
    "9w0BAQEFAAOBjQAwgYkCgYEA8d8Hc6atq78Jt1HLp9agA/wpQfsFvkYUdZ1YsdvO\n"
    "kL2janjwHQgMMCy/Njal3FUEW0OLPebKZUJ8L44JBXSlVxU4zyiiSOWld8EkTetR\n"
    "AVT3WKQq3ud+cnxv7g8rGRQp1UHZwmdbZ1wEfAYq8QjYx6m1ciMgRo7DaDQhD29k\n"
    "d+UCAwEAAaOB4zCB4DAdBgNVHQ4EFgQUL9miTJn+HKNuTmx/oMWlZP9cd4QwgbAG\n"
    "A1UdIwSBqDCBpYAUL9miTJn+HKNuTmx/oMWlZP9cd4ShgYGkfzB9MQswCQYDVQQG\n"
    "EwJVSzEUMBIGA1UECBMLQWNrbmFjayBMdGQxEzARBgNVBAcTClJoeXMgSm9uZXMx\n"
    "EDAOBgNVBAoTB25vZGUuanMxHTAbBgNVBAsTFFRlc3QgVExTIENlcnRpZmljYXRl\n"
    "MRIwEAYDVQQDEwlsb2NhbGhvc3SCCQCi9FBvpkZEjzAMBgNVHRMEBTADAQH/MA0G\n"
    "CSqGSIb3DQEBBQUAA4GBADRXXA2xSUK5W1i3oLYWW6NEDVWkTQ9RveplyeS9MOkP\n"
    "e7yPcpz0+O0ZDDrxR9chAiZ7fmdBBX1Tr+pIuCrG/Ud49SBqeS5aMJGVwiSd7o1n\n"
    "dhU2Sz3Q60DwJEL1VenQHiVYlWWtqXBThe9ggqRPnCfsCRTP8qifKkjk45zWPcpN\n"
    "-----END CERTIFICATE-----\n";


  int ret = -1, cacert_ret = -1, cacrl_ret = -1;
  mbedtls_x509_crt crt;
  mbedtls_x509_crt *cur = &crt;
  mbedtls_x509_crt cacert;
  uint32_t flags;

  mbedtls_x509_crt_init(&crt);
  mbedtls_x509_crt_init(&cacert);

  ret = mbedtls_x509_crt_parse(&crt, (const unsigned char*)PUBLIC_KEY, sizeof(PUBLIC_KEY));
  if (ret != 0) {
    mbedtls_printf("failed!\n");
  }
  mbedtls_printf("buf size: %lu, return: %d\n", sizeof(PUBLIC_KEY), ret);

  unsigned char buf[2048];
  while( cur != NULL )
  {
      ret = mbedtls_x509_serial_gets((char *)buf, sizeof(buf) - 1, &cur->sig);
      mbedtls_printf("%s\n", buf);

      cur = cur->next;
  }

  // verify
  cacert_ret = mbedtls_x509_crt_parse(&cacert, (const unsigned char*)PUBLIC_KEY, sizeof(PUBLIC_KEY));
  if (cacert_ret != 0)
  {
    mbedtls_printf("buf size: %lu, return: %d\n", sizeof(PUBLIC_KEY), ret);
  }

  cur = &crt;
  while (cur != NULL)
  {
    if(( ret = mbedtls_x509_crt_verify(cur, &cacert, NULL, NULL, &flags, my_verify, NULL )) == 0)
      mbedtls_printf( " ok\n" );

    cur = cur->next;
  }

  mbedtls_x509_crt_free (&crt);
}
