#!/usr/bin/env bash
set -e
. ./headers.sh

DEBUG=${1:-0}

for PROJECT in $PROJECTS; do
  (cd $PROJECT && DEBUG="$DEBUG" DESTDIR="$SYSROOT" $MAKE all)
done

