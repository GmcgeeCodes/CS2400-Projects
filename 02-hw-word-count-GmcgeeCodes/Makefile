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
	@echo "------------------------------------"
	echo @@@ | ./_TEST/a.out
	@echo "------------------------------------"
	echo incomplete sentence @@@| ./_TEST/a.out
	@echo "------------------------------------"
	./_TEST/a.out <_TEST/input.txt
	@echo
################################################################################


clean:
	rm -rf a.out *.o _TEST/a.out _TEST/PROGRAM.cc
