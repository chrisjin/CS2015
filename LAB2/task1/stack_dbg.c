
/* stack.c */
/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int bof(char *str)
{
    char buffer[24];
    printf("stack:%x\n", (unsigned int)(&str - 1));
//	printf("ret:%x, %x\n", (unsigned int)(*(&str - 1)), (unsigned int)__builtin_return_address(0));
//printf("buffer: %x\n", (unsigned int)(&buffer));
    /* The following statement has a buffer overflow problem */
    strcpy(buffer, str);
//printf("ret:%x, %x\n", (unsigned int)(*(&str - 1)), (unsigned int)__builtin_return_address(0));
    
return 1; }


int main(int argc, char **argv)
{
    char str[517];
    FILE *badfile;
    badfile = fopen("badfile", "r");
    fread(str, sizeof(char), 517, badfile);
    bof(str);
    printf("Returned Properly\n");
    return 1;
}
