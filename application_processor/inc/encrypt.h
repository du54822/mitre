#ifndef ENCRYPT_H
#define ENCRYPT_H

// Include necessary header files
#include <stdint.h>  // For uint8_t data type
#include <wolfssl/options.h>
#include <wolfssl/wolfcrypt/aes.h>

// Function prototype for encrypt_file
int encrypt_file(const char *input_file, const char *output_file, const unsigned char *key, const unsigned char *iv);

#endif /* ENCRYPT_H */