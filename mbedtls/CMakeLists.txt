cmake_minimum_required(VERSION 3.6)
project(sign)
project(verify)
project(ecdsa)
project(key_app)

LINK_LIBRARIES(/Users/jimtang/GitHub/c-namespace/mbedtls/mbedtls/build/library/libmbedcrypto.a)
LINK_LIBRARIES(/Users/jimtang/GitHub/c-namespace/mbedtls/mbedtls/build/library/libmbedtls.a)
LINK_LIBRARIES(/Users/jimtang/GitHub/c-namespace/mbedtls/mbedtls/build/library/libmbedx509.a)

INCLUDE_DIRECTORIES(/Users/jimtang/GitHub/c-namespace/mbedtls/mbedtls/include/)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
add_executable(sign pk_sign.c)
add_executable(verify pk_verify.c)
add_executable(ecdsa ecdsa.c)
add_executable(key_app key_app.c)
