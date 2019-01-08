#TODO: Autodetect arch
ARCHDIR=arch/i386
KERNELDIR=kernel

KCFLAGS?=-std=gnu11 -ffreestanding -O2 -Wall -Wextra
KCPPFLAGS?=
KLDFLAGS?=-nostdlib -lk -lgcc

DESTDIR?=
PREFIX=/usr
INCLUDEDIR=$(PREFIX)/include
LIBDIR?=$(PREFIX)/lib

include $(ARCHDIR)/make.config

CFLAGS:=$(KCFLAGS) $(KERNEL_ARCH_CFLAGS)
LDFLAGS:=$(KLDFLAGS) $(KERNEL_ARCH_LDFLAGS)
CPPFLAGS:=$(KCPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)

CRTBEGIN_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtend.o)

KERNEL_OBJS=\
$(KERNEL_ARCH_OBJS) \
$(KERNELDIR)/kernel.o \

LINK_LIST=\
$(CRTI_OBJ) \
$(CRTBEGIN_OBJ) \
$(KERNEL_OBJS) \
$(CRTEND_OBJ) \
$(CRTN_OBJ) \

OBJS=\
$(KERNEL_OBJS) \
$(CRTI_OBJ) \
$(CRTN_OBJ) \

.PHONY: all clean install install-headers
.SUFFIXES: .o .c .S

all: funos.bin

funos.bin: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LINK_LIST) $(LDFLAGS) 
	grub-file --is-x86-multiboot $@

.c.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS)

.S.o:
	$(AS) $< -o $@

clean:
	rm -f funos.bin
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

-include $(OBJS:.o=.d)
