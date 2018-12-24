#TODO: Autodetect arch
ARCHDIR=arch/i386
KERNELDIR=kernel

KCFLAGS?=-std=gnu99 -ffreestanding -O2 -m32 -mtune=i686 -march=i686 -Wall -Wextra -D__is_kernel
KCPPFLAGS?=
KLDFLAGS?=-nostdlib -lgcc
KLIBS?=
ASFLAGS:=--32 -mtune=i686 -march=i686

DESTDIR?=
PREFIX=/usr
INCLUDEDIR=$(PREFIX)/include
LIBDIR?=$(PREFIX)/lib

include $(ARCHDIR)/make.config

CFLAGS:=$(KCFLAGS) $(KERNEL_ARCH_CFLAGS)
LDFLAGS:=$(KLDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(KLIBS) $(KERNEL_ARCH_LIBS)

CRTI_OBJ=$(ARCHDIR)/crti.o
CRTBEGIN_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtbegin.o)
CRTEND_BOJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtend.o)
CRTN_OBJ=$(ARCHDIR)/crtn.o

KERNEL_OBJS=\
$(ARCHDIR)/boot.o \
$(KERNELDIR)/kernel.o \
$(ARCHDIR)/tty.o \

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
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LDFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot $@

.c.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS)

.S.o:
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f funos.bin
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

-include $(OBJS:.o=.d)
