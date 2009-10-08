.EXPORT_ALL_VARIABLES:

CFLAGS 			= -m32 -g -Wall -O -fleading-underscore -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I include
LD_KERNEL_FLAGS         = -T linker/linker.ld

SUBDIRS 		= setup kernel


all:
	@for dir in $(SUBDIRS);\
		do ( $(MAKE) -C $$dir all);\
	done

kernel32: setup/setup.o setup/main.o setup/portio.o debug/bochs.o kernel/kernel.o
	ld $(LD_KERNEL_FLAGS) $^ -o $@
clean:
	@echo -n Cleaning up...
	rm *.o kernel32
embed:
	sudo mount -o loop img/floppy.img /mnt
	sudo cp kernel32 /mnt/boot/kernel.bin
	sudo umount /mnt
