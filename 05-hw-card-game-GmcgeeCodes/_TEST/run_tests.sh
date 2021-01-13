#!/bin/bash
echo '\033[0;33m' "The following should report errors" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'

echo '\033[0;33m' "./a.out 4 5" '\033[m'
_TEST/a.out 4 5				# test with too many
echo '\033[0;33m' "./a.out 50" '\033[m'
_TEST/a.out 50				# test with non-triangular number
echo '\033[0;33m' "./a.out 130" '\033[m'
_TEST/a.out 130				# test with non-triangular number

echo
echo '\033[0;33m' "The following should produced the correct output" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'
echo

echo '\033[0;33m' "Default value n = 45" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'

echo '\033[0;33m' "./a.out" '\033[m'
_TEST/a.out					# test with input default 45

echo '\033[0;33m' "./a.out 6" '\033[m'
_TEST/a.out 6				# test with triangular number
echo '\033[0;33m' "###################################################################" '\033[m'
echo '\033[0;33m' "./a.out 55" '\033[m'
_TEST/a.out 55				# test with triangular number
echo '\033[0;33m' "###################################################################" '\033[m'
echo '\033[0;33m' "./a.out 120" '\033[m'
_TEST/a.out 120				# test with triangular number
