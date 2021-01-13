#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include "book.h"

using namespace std;

Book::Book(){ // Book default constructor 
	title ="***";
	year = 0;
	author = "***";
}
Book::Book(string newTitle, int newYear, string newAuthor){ // Constructor  for Book class
	title = newTitle;

	if (newYear > 0){ // If new year is greater than zero we get a new year
	year = newYear;
	}else{ // Or else year will be equal to zero 
		year = 0;
	}
	author = newAuthor;
}
Book::Book(string allData){ // Book constructor for allData
	int dataSize = allData.length(); // Length of the whole string.

	int location = allData.find("|"); // Finds the index of the first |, then gets the tile
	title = allData.substr(0,location);
	int firstIndex = location + 1;

	location = allData.find("|", firstIndex); // Finds the index of the second |, then gets the year
	int secondIndex = location + 1;
	int yearLength = location - firstIndex;
	year = stoi(allData.substr(firstIndex, yearLength)); 
	if (year < 0){
		year = 0;
	}


	int authorLength = dataSize - secondIndex; // Finds the size of the author and gets the author
	author = allData.substr(secondIndex, authorLength);
	
}
void Book::setTitle(string newTitle){ // Setter for title
	title = newTitle;
}
void Book::setAuthor(string newAuthor){ // Setter for author
	author = newAuthor;
}
void Book::setYear(int newYear){ // Setter for year if the year is greater than zero 
	if(newYear > 0){
		year = newYear;
	}
}
string Book::getTitle(){ // Getter fot title
	return  title;
}
string Book::getAuthor(){ // Getter for author
	return author;
}
int Book::getYear(){ // Getter for year
	return year;
}
bool Book::matchTitle(string targetTitle){ // Bool member function of Book class to find the target Title
	string dummytargetTitle = targetTitle;
	string dummyTitle = title; 
	lowercaseString(dummytargetTitle);
	lowercaseString(dummyTitle);
	
	if (dummyTitle.find(dummytargetTitle) != string::npos){
		return true;
	}
	return false;	
}
bool Book::matchAuthor(string targetAuthor){ // Bool function of Book class to find target authot
	string dummyAuthor = author; // Dummy string variables created
	string dummytargetAuthor = targetAuthor;

	lowercaseString(dummytargetAuthor); // Conversion to everything lowercase
	lowercaseString(dummyAuthor);
	if (dummyAuthor.find(dummytargetAuthor) != string::npos){
		return true;
	}
	return false;	
}
bool Book::matchYear(string targetYear){ // Bool member function of Book class to find target year
	string stringYear = to_string(year); // Convert year to a string so we can find it 

	if (stringYear.find(targetYear) != string::npos){
		return true;
	}
	return false;
}
bool Book::match(string target){ // Function to see if the target matches the specific target for Book class

	if (matchTitle(target) == 1){
		return true;
	}
	if (matchAuthor(target) == 1){
		return true;
	}
	if (matchYear(target) == 1){
		return true;
	}

	return false;
}
void Book::lowercaseString(string &targetString){ // lowercase string function for Book class 
	int targetLength = targetString.length(); // Int to get total length of string 
	for(int i = 0; i < targetLength; i++){
		if (targetString[i] >= 'A' && targetString[i] <= 'Z'){ 
			targetString[i] = tolower(targetString[i]);
		}
	}
}
void Book::output(){  // Output helper function for class Book
	cout <<"The author is: "<< author << endl;
	cout<<"The title is: "<< title << endl;
	cout<<"The year is: "<< year << endl;
}