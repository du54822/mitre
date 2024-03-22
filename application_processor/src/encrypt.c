// Include necessary headers
#include <stdio.h>
#include <wolfssl/options.h>
#include <wolfssl/wolfcrypt/aes.h>
#include "/Users/dorisulysse/Desktop/mitre/application_processor/inc/encrypt.h"


#define BUFFER_SIZE 4096
#define AES_KEYSIZE_256 32 // AES-256 key size in bytes

int encrypt_file(const char *input_file, const char *output_file,
                 const unsigned char *key, const unsigned char *iv) {
    FILE *in_file = fopen(input_file, "rb");
    if (!in_file) {
        fprintf(stderr, "Error: Unable to open input file\n");
        return 1;
    }

    FILE *out_file = fopen(output_file, "wb");
    if (!out_file) {
        fclose(in_file);
        fprintf(stderr, "Error: Unable to open output file\n");
        return 1;
    }

    Aes aes;
    wc_AesSetKey(&aes, key, AES_KEYSIZE_256, iv, AES_ENCRYPTION);

    unsigned char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in_file)) > 0) {
        wc_AesCbcEncrypt(&aes, buffer,buffer, bytes_read);
        fwrite(buffer, 1, bytes_read, out_file);
    }

    fclose(in_file);
    fclose(out_file);

    return 0;
}
