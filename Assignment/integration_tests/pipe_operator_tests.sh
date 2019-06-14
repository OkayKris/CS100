#!/bin/bash
echo not really sure how to test pipe > test.txt
echo i just know it pipes one output to other input > test2.txt
cat < test.txt | tr a-z A-Z > allcaps.txt
cat < allcaps.txt | tr A-Z a-z > nowlower.txt
ls -a | grep test
rm -f test.txt
rm -f test2.txt
rm -f allcaps.txt
rm -f nowlower.txt
exit
