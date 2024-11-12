#include <glib.h>
#include <stdint.h>
#include <gcrypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cli.h"

#define KEY_MAX_LENGHT 57
#define UNLOCKED_DATA_SIZE 32

// From https://github.com/wynick27/GameRE/blob/main/FC3LockStringGenerator/FC3LockStringGenerator/MainWindow.xaml.cs
uint8_t unlocked_data[] = {
  0x0f, 0x0f, 0x07, 0x05, 0x07, 0x07, 0x07, 0x07, 0x1f, 0x1f, 0x1b, 0x1a, 0x1b, 0x1b, 0x1b, 0x1b,
  0x2f, 0x2f, 0x2d, 0x25, 0x2d, 0x2d, 0x2d, 0x2d, 0x3f, 0x3f, 0x3e, 0x3a, 0x3e, 0x3e, 0x3e, 0x3e
};


uint8_t *encrypt_data(const char *key) {
  uint8_t *encrypted_data;
  gcry_cipher_hd_t cipher;
  size_t key_len;

  encrypted_data = malloc(UNLOCKED_DATA_SIZE);
  key_len = strlen(key);

  gcry_error_t err = gcry_cipher_open(&cipher, GCRY_CIPHER_BLOWFISH, GCRY_CIPHER_MODE_ECB, 0);
  if (err) {
    fprintf(stderr, "Failed to open Blowfish cipher: %s\n", gcry_strerror(err));
    exit(1);
  }

  err = gcry_cipher_setkey(cipher, key, key_len);
  if (err) {
    fprintf(stderr, "Failed to set Blowfish key: %s\n", gcry_strerror(err));
    exit (1);
  }

  err = gcry_cipher_encrypt(cipher, encrypted_data, UNLOCKED_DATA_SIZE, unlocked_data, UNLOCKED_DATA_SIZE);
  if (err) {
    fprintf(stderr, "Failed to encrypt data: %s\n", gcry_strerror(err));
    exit(1);
  }

  gcry_cipher_close(cipher);

  return encrypted_data;
};

int main(int argc, char **argv) {
  ProgramOptions *options;

  options = get_program_options(&argc, &argv);

  if (strlen(options->username) > KEY_MAX_LENGHT - 1) {
    options->username[KEY_MAX_LENGHT - 1] = 0;
  }

  uint8_t *data = encrypt_data(options->username);
  printf("Encrypted data:\n");
  for (int i = 0; i < UNLOCKED_DATA_SIZE; i++) {
    printf("%02x ", data[i]);
  }

  printf("\n");

  // encode
  gchar *base64_str = g_base64_encode(data, UNLOCKED_DATA_SIZE);
  printf("Data: %s\n", base64_str);

  return 0;
}
