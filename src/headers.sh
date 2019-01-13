#!/usr/bin/env bash
set -e
. ./config.sh

mkdir -p "$SYSROOT"

for PROJECT in $SYSTEM_HEADER_PROJECTS; do
    (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install)
done
