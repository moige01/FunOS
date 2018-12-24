SYSTEM_HEADER_PROJECTS="kernel"
PROJECTS="kernel"
 
export MAKE=${MAKE:-make}
# export HOST=${HOST:-$(./default-host.sh)}

export AS=${HOST}-as
export CC=${HOST}-gcc
 
export PREFIX=/usr
export BOOTDIR=/boot
export LIBDIR=$PREFIX/lib
export INCLUDEDIR=$PREFIX/include
 
# Configure the cross-compiler to use the desired system root.
export SYSROOT="$(pwd)/sysroot"
export CC="$CC --sysroot=$SYSROOT"
 
