#include<types.h>
#include<setup/portio.h>

/*
	"Out" an 8 bit byte
*/
void outportb(u32 port, u8 outdata)
{
	__asm__ __volatile__("outb %b0, %w1" : : "a"(outdata), "d"(port));
}

/*
	"In" an 8 bit byte
*/
u8 inportb(u16 port)
{
	u8 retVal;

	__asm__ __volatile__("inb %1, %0" : "=a"(retVal) : "d"(port));
	return retVal;
}

/*
	"Out" a 16 bit word
*/
void outportw(u16 port, u16 data)
{
	__asm__ __volatile__("outw %1, %0" : : "dN"(port), "a"(data));
}

/*
	"In" a 16 bit word
*/
u16 inportw(u16 port)
{
	u16 retVal;
	__asm__ __volatile__("inw %1, %0" : "=a"(retVal) : "d"(port));
	return retVal;
}

/*
	"Out" a 32 bit double word
*/
void outportdw(u16 port, u32 data)
{
	__asm__ __volatile__("outl %1, %0" : : "dN"(port), "a"(data));
}

/*
	"In" a 32 bit double word
*/
u32 inportdw(u16 port)
{
	u32 retVal;

	__asm__ __volatile__("inl %%dx, %%eax" : "=a"(retVal) : "d"(port));
	return retVal;
}
