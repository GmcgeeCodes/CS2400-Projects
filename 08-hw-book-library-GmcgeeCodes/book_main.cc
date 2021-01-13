/*
 *        File: book_main.cc
 *      Author: Gerald McGee
 *        Date: 4/26/19
 * Description: This program gives the user the ability to control information in a database of books. The user 
 * has the ability to search by year, title, and author and print the search results to user. The other options 
 * (new,delete) allow the user to add and delete book objects from the database. The program also allows the user to search
 * by a target in general by not specifying an option but just by typing in the target. It achieves this by using built in functions of
 * the book class, search functions, and different types of output functions.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "book.h"

using namespace std;
// function prototypes
void searchAuthor(vector <Book> &bookList, string target);
/* The purpose of this function is to search the database based on author and print the results to the user.
 * The function takes a vector of Books called bookList and then a target string to find results that match.
 * It is a void function so it does not return anything.
*/
void searchTitle(vector <Book> &bookList, string target);
/* The purpose of this function is to search the database based on the title and print the results to the user.
 * The function takes a vector of Books called bookList and then a target string to find results that match.
 * It is a void function so it does not return anything.
*/
void searchYear(vector <Book> &bookList, string target);
/* The purpose of this function is to search the database based on year and print the results to the user.
 * The function takes a vector of Books called bookList and then a target string to find results that match.
 * It is a void function so it does not return anything.
*/
void searchTarget(vector <Book> &bookList, string target);
/* The purpose of this function is to search the database based on a target string and print the results to the user.
 * The function takes a vector of Books called bookList and then a target string to find results that match.
 * It is a void function so it does not return anything.
*/
void deleteVector(vector <Book> &bookList, int deleteIndex);
/* The purpose of this function is to delete an element of the database. The function takes the vector a vector of Books
 * and an integer deleteIndex produced by the the search function to find the index of the element that must be deleted.
 * It is a void function so it does not return anything.
 *
*/
int search(const vector <Book> &bookList, string target);
/* The purpose of this function is to search an element of the vector of Books bookList and see if it matches the target string. 
 * The function takes a constant vector of Books and a string target for comparison and returns an integer type to the delete section 
 * of the program.
*/
void outputBack(vector <Book> &booksList, ofstream &outStream);
/*
 * The purpose of this function is to import the database information back into the specified file after the info gets deleted.
 * It takes the vector of Books and and outStream to print the information back to the file. It is a void function so it does not return anything.
*/

int main(int argc, char const *argv[]) { // start of main
    ifstream inStream; // Instream declaration
    ofstream outStream; // outStream dec
    vector <Book> booksList; // vector to hold books in file 

    if (argc < 2){
        cout << "Error: not enough options were entered!" << endl;

        exit(1);

    }
    if (argc > 3){
        cout << "Error too many options were entered!" << endl;
        exit(1);

    }
    cout << "Please enter a filename: "; // Getting the filename from user 
    string filename;
    cin >> filename;
   
    inStream.open(filename.c_str()); // Opening file and checking for failure 
    if (inStream.fail()){
        cout << "Error: file failed to open!" << endl;
        exit(1);
    }

    string bookLine; // bookLine variable for each line that getLine gets
    string choice = argv[1]; // Storing argv[1] in choice
    string target = "";  // The target variable for what is searched for 
    int zeroGenerator = 0; // Variable created for zero's generated by an empty line 

    getline(inStream, bookLine);
    if (bookLine.length() == 0){ // This code filters out the empty strings, if more than 50 zeros are generated than we have reached the end of file that is a blank space
         zeroGenerator = 1;

        while (bookLine.length() == 0){ 
            getline(inStream, bookLine); // if getLine produces a line that is not equal to zero it exits the loop
            zeroGenerator++;
            if (zeroGenerator > 50)
                 break;
            
        }
    }
    
    while(!(inStream.eof())){
        Book b(bookLine);
        booksList.push_back(b);

        getline(inStream, bookLine);

        if (bookLine.length() == 0){ // This code filters out the empty strings
            zeroGenerator = 1;
            while (bookLine.length() == 0){
             getline(inStream, bookLine);
             zeroGenerator++;

             if (zeroGenerator > 50) // If more than 50 empty strings are generated we have reached the end of file
                 break;
            }
        }
    }
    inStream.close(); // close input file
    outStream.open(filename.c_str()); // open the same file except in the outStream
    if (outStream.fail()){
        cout << "Error: Output file failed to open!" << endl;
        exit(1);
    }

    if (argc == 2){ // If arg c equals 2 we are searching by target
        target = argv[1]; // The search target is located in argv[1] when argc == 2
        searchTarget(booksList, target);
        outputBack(booksList, outStream);
    }
    if (argc == 3){ // if arg c == 3 we are searching by option 
        target = argv[2]; // the search target is located in argv[2] when argc == 3
        if (!(choice == "-a" || choice == "-t"|| choice == "-y" || choice == "-n" || choice == "-d")){ // If the choice does not equal one of the options the program will quit
            cout << "Invalid option!" << endl;
            exit(1);
        }
        if (choice == "-a"){
            searchAuthor(booksList,target); // search for author and print results to user 
            outputBack(booksList, outStream); // output everything back to file
        }
        else if (choice == "-t"){
            searchTitle(booksList, target); // seach and print
            outputBack(booksList, outStream); // output
        }
        else if (choice == "-y"){
            searchYear(booksList, target); // search and print
            outputBack(booksList,outStream); // output
        }
        else if (choice == "-n"){
            Book n(target); // This code will create a new object of book using the user input and push it back
            booksList.push_back(n);

            outputBack(booksList, outStream); // output back to file
        }
        else if (choice == "-d"){
          int deleteIndex = search(booksList, target); // This variable hols the index of the delete target 

            if (deleteIndex != -1){ // If the target is found the target at the index will be deleted and outputted back to the file
              deleteVector(booksList, deleteIndex);
              outputBack(booksList, outStream);
            }
            else{
             cout << "Delete target could not be found!" << endl; 
            }   
          
        }

    }
    outStream.close(); // close file 
	return 0;
}// main
void searchAuthor(vector <Book> &bookList, string target){ // This will search the vector based on Author and print the info to the user 
     for (int i = 0; i < bookList.size(); i++){
        if (bookList[i].matchAuthor(target)){
            cout << bookList[i];  
        }
    }
}

void searchTitle(vector <Book> &bookList, string target){ // This will search the vector based on Title and print the info to the user 
    for (int i = 0; i < bookList.size(); i++){
        if (bookList[i].matchTitle(target)){
            cout << bookList[i];  
        }      
    }
}

void searchYear(vector <Book> &bookList, string target){ // This will search the vector based on year and print the info to the user
    for (int i = 0; i < bookList.size(); i++){
        if (bookList[i].matchYear(target)){
            cout << bookList[i];  
        }
    }
}

void searchTarget(vector <Book> &bookList, string target){  // This will search to find the target and print the book information to user 
     for (int i = 0; i < bookList.size(); i++){
        if (bookList[i].match(target)){
            cout << bookList[i];  
        } 
    }
}

void deleteVector(vector <Book> &bookList, int deleteIndex){ // Function to delete a book at the specified position 
    bookList.erase(bookList.begin() + deleteIndex);
}

int search(const vector <Book> &bookList,  string target){ // This function will search and find the index of the target 
    for(size_t i =0; i < bookList.size(); i++){
        if (target == bookList[i].getTitle()){
            return i;
        }
    }
    return -1;
}
void outputBack(vector <Book> &booksList, ofstream &outStream){ // Function that outputs the vector back into the file
    for(int i = 0; i < booksList.size(); i++){
        outStream << booksList[i].getTitle() << "|" << booksList[i].getYear() << "|" << booksList[i].getAuthor() << endl;
    }

}

