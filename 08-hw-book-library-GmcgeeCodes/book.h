#ifndef BOOK_H
#define BOOK_H 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>


using namespace std;

class Book{ // Book class
	public:
	// Constructores for Book class
	Book();
	Book(string newTitle, int newYear, string newAuthor);
	Book(string allData);

	// Setters
	void setTitle(string newTitle);
	void setYear(int newYear);
	void setAuthor(string newAuthor);
	// Getters 
	string getTitle() const;
	int getYear();
	string getAuthor();

	//Member functions
	bool matchTitle(string targetTitle);
	bool matchYear(string targetYear);
	bool matchAuthor(string targetAuthor);
	bool match(string target);

	//Helper function
	void output(); // no longer needed

	private:
	string title; // string variable for the title of the book
	int year;  // int variable for the year the book came out
	string author; // string variable for the author of the book
	void lowercaseString(string &targetString); // Private function to convert strings to all lowercase 
	friend ostream& operator <<(ostream& outs, Book& bookOutput); // Output overload
};
#endif