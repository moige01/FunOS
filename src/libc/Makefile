CFLAGS?=-O2
CPPFLAGS?=
LDFLAGS?=
LIBS?=
 
DESTDIR?=
PREFIX?=/usr
EXEC_PREFIX?=$(PREFIX)
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib
 
CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra
LIBK_CFLAGS:=$(CFLAGS)
 
FREEOBJS=\
stdio/printf.o \
stdio/putchar.o \
stdio/puts.o \
stdlib/abort.o \
stdlib/itoa.o \
string/memcmp.o \
string/memcpy.o \
string/memmove.o \
string/memset.o \
string/strlen.o \
string/strrev.o \
 
HOSTEDOBJS=\
 
OBJS=\
$(FREEOBJS) \
$(HOSTEDOBJS) \
 
LIBK_OBJS=$(FREEOBJS:.o=.libk.o)
 
#BINARIES=libc.a libk.a # Not ready for libc yet.
BINARIES=libk.a
 
.PHONY: all clean install install-headers install-libs
.SUFFIXES: .o .libk.o .c .S
 
all: $(BINARIES)
 
libc.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
 
libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)
 
.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS)
 
.c.S:
	$(CC) -MD -c $< -o $@ $(CFLAGS)
 
.c.libk.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(LIBK_CFLAGS)
 
.S.libk.o:
	$(CC) -MD -c $< -o $@ $(LIBK_CFLAGS)
 
clean:
	rm -f $(BINARIES) *.a
	rm -f $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) $(LIBK_OBJS:.o=.d) *.d */*.d */*/*.d
 
install: install-headers install-libs
 
install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.
 
install-libs: $(BINARIES)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(BINARIES) $(DESTDIR)$(LIBDIR)
 
-include $(OBJS:.o=.d)
-include $(LIBK_OBJS:.o=.d)
