#!/bin/bash
ls -a; echo hello && mkdir test || echo world test created; git status
rm -r test; ls
echo Does this work || echo no it didnt lol
echo does this work part 2 && echo i think so
