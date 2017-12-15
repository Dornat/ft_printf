#!/bin/bash

ls *.c > test
sed -i '' 's/$/ \\/' test
sed -i '' 's/^/\	\	/' test
sed -i '' '15r test' Makefile
#sed -i '' '/SRC/r test' Makefile
rm -f test
