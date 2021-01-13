/*
 *        File: book_main.cc
 *      Author: Enter your name
 *        Date: Enter the date
 * Description: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include "book.h"

using namespace std;

int main(int argc, char const *argv[]) {

	Book b;
	b.output();
	Book b2("Old Yeller", 1784, "Terrance");
	b2.output();
	Book b3("Old Yeller|1997|Fritz");
	b3.output();
	b3.setTitle("Hunger Games");
	b3.setAuthor("Katniss Everdeen");
	b3.setYear(2008);

	cout <<"New title: "<< b3.getTitle() << endl;
	cout <<"New Author: "<< b3.getAuthor() << endl;
	cout <<"New Year: "<< b3.getYear() << endl;

	if(b3.matchTitle("Game") == 1){
		cout <<"Target title has been found!" << endl;
	}else{
		cout <<"Target title has not been found!" << endl;
	}

	if (b3.matchAuthor("Rear") == 1){
		cout <<"Target author has been found!" << endl;

	}else{
		cout <<"Target author has not been found!" << endl;
	}

	if(b3.matchYear("1999") == 1){
		cout <<"Target year has been found!" << endl;
	}else{
		cout <<"Target year has not been found!" << endl;

	}

	if(b3.match("20") == 1){
		cout <<"Target has been found!" << endl;
	}else{
		cout <<"Target has not been found!" << endl;
	}

	b3.output();
	
	return 0;
}// main

