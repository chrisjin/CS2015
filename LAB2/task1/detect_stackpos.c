
/* stack.c */
/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
unsigned int get_pc () { return (unsigned int)__builtin_return_address(0); }

int printkk(char* str)
{
	printf("MMMMM\n");
//*(&str - 1) = (char*)134513740;
}

int bof(char *str)
{
   *(&str - 1) = (char*)printkk;
    char buffer[24];
printf("sizeint:%d\n", sizeof(void*));
printf("arg: %u\n", (unsigned int)(&str));
printf("stack:%u\n", (unsigned int)(*(&str - 1)));
printf("buffer: %u\n", (unsigned int)(&buffer));
    strcpy(buffer, str);
printf("ret:%u\n", (unsigned int)__builtin_return_address(0));

printf("____Callstack\n");
unsigned int* p = (unsigned int*)(&str);
int i = 0;
for(i = 0; i < 20; i++)
{
	printf("%d,%u\n",i, *(p-i));
}
printf("___callstack\n");
return 1; }



int main(int argc, char **argv)
{
	printf("main: %u\n", (unsigned int)main);
    char * text = "aaaa";
	printf("pc:%u\n", get_pc());
    bof(text);
printf("pcafter:%u\n", get_pc());
printf("pcafter:%u\n", get_pc());
    return 1;
}
