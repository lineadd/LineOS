#include<types.h>
#include<setup/portio.h>

void dputc(int c)
{
        outportb(0xe9, c);
}

void bochsPrint(char *s)
{
        while(*s)dputc(*s++);
}
