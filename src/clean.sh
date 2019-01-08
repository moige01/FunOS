#!/usr/bin/env bash
set -e
. ./config.sh

for PROJECT in $PROJECTS; do
  (cd $PROJECT && $MAKE clean)
done

echo "Removing sysroot"
rm -rf sysroot
