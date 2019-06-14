#!/bin/bash
echo Test > test.txt
echo does this work >> test.txt && echo i hope this works >> test.txt
echo did this overwrite? > test.txt
echo last check > text.txt && cat < test.txt
ls -a
rm -f test.txt
exit
