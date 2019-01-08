SYSTEM_HEADER_PROJECTS="kernel libc"
PROJECTS="libc kernel"
 
export MAKE=${MAKE:-make}
export HOST=i686-elf

export AR=${HOST}-ar
export AS=${HOST}-as
export CC=${HOST}-gcc
 
export PREFIX=/usr
export BOOTDIR=/boot
export LIBDIR=$PREFIX/lib
export INCLUDEDIR=$PREFIX/include
 
# Configure the cross-compiler to use the desired system root.
export SYSROOT="$(pwd)/sysroot"
export CC="$CC --sysroot=$SYSROOT -isystem=$INCLUDEDIR"
 
