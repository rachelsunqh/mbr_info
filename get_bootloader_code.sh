#!/bin/bash
dd if=$1 of=mbr.bin bs=446 count=1 >/dev/null
ndisasm mbr.bin>$2
rm -rf mbr.bin>/dev/null

