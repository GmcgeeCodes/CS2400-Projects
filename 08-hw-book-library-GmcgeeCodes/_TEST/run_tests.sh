#!/bin/bash
echo '\033[0;33m' "The following should report errors" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'

_TEST/a.out
_TEST/a.out 1 2 3

echo '\033[0;33m' "./a.out 1 2 3" '\033[m'
echo
echo '\033[0;33m' "###################################################################" '\033[m'
echo '\033[0;33m' "The following should produced the correct output" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'

echo '\033[0;33m' "./a.out -t ClaIR" '\033[m'
_TEST/a.out -t ClaIR

echo '\033[0;33m' "./a.out -y 1964" '\033[m'
_TEST/a.out -y 1964

echo '\033[0;33m' "./a.out -a McKin" '\033[m'
_TEST/a.out -a McKin

echo '\033[0;33m' "./a.out McKin" '\033[m'
_TEST/a.out McKin

echo '\033[0;33m' "./a.out -n \"Problem Solving with C++|2018|Walter Savitch\" " '\033[m'
_TEST/a.out -n "Problem Solving with C++|2018|Walter Savitch"

echo '\033[0;33m' "./a.out C++" '\033[m'
_TEST/a.out c++

echo '\033[0;33m' "./a.out -d \"Problem Solving with C++\"" '\033[m'
_TEST/a.out -d "Problem Solving with C++"

echo '\033[0;33m' "./a.out C++" '\033[m'
_TEST/a.out c++
echo '\033[0;33m' "###################################################################" '\033[m'

