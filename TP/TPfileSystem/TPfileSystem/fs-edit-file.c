#include <assert.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_usage(char *executable, char *msg) {
  printf("Error : %s\n", msg);
  printf("Usage : %s <file-to-edit> output\n", executable);
  printf("Usage : %s <file-to-edit> modify <address> <value>\n", executable);
  printf("Usage : %s <file-to-edit> insert <address> <value>\n", executable);
  printf("Usage : %s <file-to-edit> append <value>\n", executable);
  printf("Usage : %s <file-to-edit> remove <address>\n", executable);
  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc < 3)
    print_usage(argv[0], "wrong parameters");


  int address;
  uint8_t value;
  int rv;
  int nbytes;
  int offset = 0;

  if (!strcmp(argv[2], "output")) {
    while (1) {
      /* Read a byte. Check the returned value is correct.
       */

      /* Exit when we reach end of file or cannot read a value.
       */
      if (nbytes != sizeof(value)) {
        printf("\n");
        break;
      }

      if (offset % 4 == 0) {
        /* Start a new line.
         */
        printf("\n");
        /* Print the file offset.
         */
        printf("%08x :", offset);
      }
      printf(" %02x", value);
      offset = offset + sizeof(value);
    }
  } else if (!strcmp(argv[2], "modify")) {
    if (argc != 5)
      print_usage(argv[0], "wrong parameters for operation 'modify'");

    rv = sscanf(argv[3], "%x", &address);
    assert(rv == 1);
    rv = sscanf(argv[4], "%hhi", &value);
    assert(rv == 1);

    /* Move file index to address with lseek().
     */

    /* Modify the current byte with value.
     */

  } else if (!strcmp(argv[2], "insert")) {
    if (argc != 5)
      print_usage(argv[0], "wrong parameters for operation 'insert'");

    rv = sscanf(argv[3], "%x", &address);
    assert(rv == 1);
    rv = sscanf(argv[4], "%hhx", &value);
    assert(rv == 1);

    /* Move file index to the byte.
     */

    while (address <= offset) {
      uint8_t data = 0;
      /* Move current byte one byte forward.
       */
    }
    /* Modify the current byte with value.
     */

  } else if (!strcmp(argv[2], "append")) {
    if (argc != 4)
      print_usage(argv[0], "wrong parameters for operation 'append'");

    rv = sscanf(argv[3], "%hhx", &value);
    assert(rv == 1);


  } else if (!strcmp(argv[2], "remove")) {
    if (argc != 4)
      print_usage(argv[0], "wrong parameters for operation 'remove'");

    rv = sscanf(argv[3], "%x", &address);
    assert(rv == 1);

    /*  Build a name for a temporary file
     */
    char tmp_filename[32];
    rv = mkstemp(tmp_filename);
    assert(0 <= rv);

/* Open the temporary file to write part of the original file
 */
    for (int i = 0; i < address; i = i + sizeof(value)) {
      /* Read bytes from original file and write them in the
       * temp file.
       */
    }

    /* Remove original file and rename temporary one.
     */
    /* Close tmp file.
     */

  } else
    print_usage(argv[0], "wrong operation");

    /* Close file.
     */
}
