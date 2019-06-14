#!/bin/bash
[ -e header ] && echo A
[ -f src/assn2.cpp ] && echo B
[ -d testdir ] || echo C && echo D
test -e test.cpp || echo E
test -f testdir || echo F
[ -e header/AndConnector.cpp ] && echo G
[ -f header/muahaha.cpp ] || echo H