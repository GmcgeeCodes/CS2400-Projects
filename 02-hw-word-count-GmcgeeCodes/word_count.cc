/*
 *        File: word_count.cc
 *      Author: Gerald McGee
 *        Date: February 11 11:59 p.m.
 * Description: This program is designed to find the number of words and sentences from text  that was entered  by the user. 
 *               It prints the words, sentences, and average words per sentences. If the user fails to enter text or words it produces an error message so that the user 
 *               is aware. 
 *
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[]) {   //main function 

    double totalWords = 0;   // declaration for counter for totalWords
    double sentTotal = 0;    // declaration for counter of sentence total 

    string cinWord = ""; // single word received from Cin

    // Where I get user input also for sentinel loop 
    cout << "Enter a paragraph... "<< endl; 
    cin >> cinWord; 


    // While loop for adding the words to paragraph and incrementing totalWords +1 for each space
    while ( cinWord != "@@@") {
        cin >> cinWord;
     
        totalWords++; 
    // Finding the lastChar to figure out sentences
        int length = cinWord.length();
        char lastChar = cinWord.at(length - 1);

        if (lastChar == '.' || lastChar == '?')
        {

        sentTotal++; 

        }   

 
    } 

    // Printing the word and sentence count
    cout << "Word count: "<< totalWords << endl;
    cout << "Sentence Count: "<< sentTotal << endl; 
    // One decimal point code
    cout.setf (ios::fixed);
    cout.setf (ios::showpoint);
    cout.precision(1);
    // if else if else if, statement for the calculation of avgWords per Sentence
    if (sentTotal > 0 && totalWords >  0 ) {

     double avgWordsSent = totalWords / sentTotal;  

      cout << "Average words per sentence: "<< avgWordsSent << endl; 

    }
    else if (sentTotal == 0 && totalWords == 0) {

        cout << "You did not enter any text!" << endl;
    }
    else if (totalWords > 0 && sentTotal == 0) {

        cout << "You did not enter any sentences!" << endl;
    }


    
    return 0;
} // end of main function 