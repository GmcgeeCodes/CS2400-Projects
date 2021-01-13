# Makefile for compiling a single program
# Also includes testing command
#
#

#Variables
CFLAGS = -Wall -std=c++11
CC = g++

# Replace with your own file names in the following two lines.
a.out:
	sh _TEST/configure.sh
	$(CC) $(CFLAGS) _TEST/PROGRAM.cc -o a.out

########################### DO NOT MODIFY THIS RULE ############################
#           make and run the tests: make run_tests                             #
################################################################################
run_tests:
	sh _TEST/configure.sh
	$(CC) $(CFLAGS) _TEST/PROGRAM.cc -o _TEST/a.out
	# modify for an assignment
	echo violations.txt 222 | _TEST/a.out					# test with input 10 20
	echo violations.txt 111 | _TEST/a.out 					# test with input 50 90
	echo violations.txt	-999 | _TEST/a.out					# test with input 0	 15
	echo violations123.txt	222 | _TEST/a.out					# test with input 0	 15
################################################################################


clean:
	rm -rf a.out *.o _TEST/a.out _TEST/PROGRAM.cc
