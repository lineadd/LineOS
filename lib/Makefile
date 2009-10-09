OBJECTS = stdio/doprintf.o string/string.o

.SUFFIXES:      .c .o .asm
%.o:%.asm
	@echo Compiling $<
	nasm -f elf $< -o $*.o

%.o:%.c
	@echo Compiling $<
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(OBJECTS)
