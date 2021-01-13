#!/bin/bash
echo '\033[0;33m' "The following should report errors" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'

_TEST/a.out
_TEST/a.out emails.txt
_TEST/a.out 1 2 3

echo '\033[0;33m' "./a.out 1 2 3" '\033[m'
echo
echo '\033[0;33m' "###################################################################" '\033[m'
echo '\033[0;33m' "The following should produced the correct output" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'

echo '\033[0;33m' "./a.out input_file output_file" '\033[m'
_TEST/a.out website.html output.txt

echo '\033[0;33m' "Output the content of the output file" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'
cat output.txt
echo '\033[0;33m' "###################################################################" '\033[m'

