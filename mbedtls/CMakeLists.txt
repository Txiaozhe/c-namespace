cmake_minimum_required(VERSION 3.6)
project(sign)

LINK_LIBRARIES(/Users/jimtang/GitHub/c-namespace/mbedtls/mbedtls/build/library/libmbedcrypto.a)
LINK_LIBRARIES(/Users/jimtang/GitHub/c-namespace/mbedtls/mbedtls/build/library/libmbedtls.a)
LINK_LIBRARIES(/Users/jimtang/GitHub/c-namespace/mbedtls/mbedtls/build/library/libmbedx509.a)

INCLUDE_DIRECTORIES(/Users/jimtang/GitHub/c-namespace/mbedtls/mbedtls/include/)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
add_executable(sign demo.c)
