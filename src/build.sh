#!/usr/bin/env bash
set -e
. ./headers.sh

for PROJECT in $PROJECTS; do
  (cd $PROJECT && $MAKE all)
done
