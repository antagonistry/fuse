#!/bin/bash

CC="gcc"
TARGET="fuse"
SOURCE="main.c"
CFLAGS="-Ofast --static -ansi"

$CC $CFLAGS -o $TARGET $SOURCE
