#include <stdio.h>
#include "mbedtls/pk.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/entropy.h"
#include "mbedtls/md.h"
#include "mbedtls/platform.h"
#include "string.h"

int main( int argc, char *argv[] )
{
    FILE *f;
    int ret = 1;
    int exit_code = MBEDTLS_EXIT_FAILURE;
    mbedtls_pk_context pk;
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    unsigned char hash[32];
    unsigned char buf[MBEDTLS_MPI_MAX_SIZE];
    char filename[512];
    const char *pers = "mbedtls_pk_sign";
    size_t olen = 0;

    mbedtls_entropy_init( &entropy );
    mbedtls_ctr_drbg_init( &ctr_drbg );
    mbedtls_pk_init( &pk );

    if( argc != 3 )
    {
        mbedtls_printf( "usage: mbedtls_pk_sign <key_file> <filename>\n" );
        goto exit;
    }

    mbedtls_printf( "\n  . Seeding the random number generator..." );
    fflush( stdout );

    if( ( ret = mbedtls_ctr_drbg_seed( &ctr_drbg, mbedtls_entropy_func, &entropy,
                               (const unsigned char *) pers,
                               strlen( pers ) ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_ctr_drbg_seed returned -0x%04x\n", -ret );
        goto exit;
    }

    mbedtls_printf( "\n  . Reading private key from '%s'", argv[1] );
    fflush( stdout );

    if( ( ret = mbedtls_pk_parse_keyfile( &pk, argv[1], "" ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! Could not parse '%s'\n", argv[1] );
        goto exit;
    }

    /*
     * Compute the SHA-256 hash of the input file,
     * then calculate the signature of the hash.
     */
    mbedtls_printf( "\n  . Generating the SHA-256 signature" );
    fflush( stdout );

    if( ( ret = mbedtls_md_file(
                    mbedtls_md_info_from_type( MBEDTLS_MD_SHA256 ),
                    argv[2], hash ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! Could not open or read %s\n\n", argv[2] );
        goto exit;
    }

    if( ( ret = mbedtls_pk_sign( &pk, MBEDTLS_MD_SHA256, hash, 0, buf, &olen,
                         mbedtls_ctr_drbg_random, &ctr_drbg ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_pk_sign returned -0x%04x\n", -ret );
        goto exit;
    }

    /*
     * Write the signature into <filename>.sig
     */
    mbedtls_snprintf( filename, sizeof(filename), "%s", argv[2] );

    if( ( f = fopen( filename, "wb+" ) ) == NULL )
    {
        mbedtls_printf( " failed\n  ! Could not create %s\n\n", filename );
        goto exit;
    }

    if( fwrite( buf, 1, olen, f ) != olen )
    {
        mbedtls_printf( "failed\n  ! fwrite failed\n\n" );
        fclose( f );
        goto exit;
    }

    fclose( f );

    mbedtls_printf( "\n  . Done (created \"%s\")\n\n", filename );

    exit_code = MBEDTLS_EXIT_SUCCESS;

exit:
    mbedtls_pk_free( &pk );
    mbedtls_ctr_drbg_free( &ctr_drbg );
    mbedtls_entropy_free( &entropy );


    return( exit_code );
}
