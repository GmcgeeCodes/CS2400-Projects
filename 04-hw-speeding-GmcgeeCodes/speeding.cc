/*
 *        File: speeding.cc
 *      Author: Gerald McGee
 *        Date: 3/4/18
 * Description: This program reads a license number from the user and then uses a txt file to print the number of violations
 * a license number has. If the user has over six violations the file will print that the license should be suspended. I achieve this by using two
 * functions.One function to count the number of violations and return that number to the main. Then I use another void function to display the 
 * results to the user.
 *
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

//function prototypes
int violationsNum(ifstream &inStream, int licenseNum);
/* The purpose of this function is to count the number of violations a license number has. The function takes 
* an input stream and a license number from the user ,and then returns an integer which is the license number.
*
*/
void printResults(int licenseNum, int violations); 
/*
* The purpose of this function is to print the results and the user whether a license should be supsended or not.
* The function takes the license number and the number of violations to print these results. It is a void function
* so it does not return anything.
*
*/

int main(int argc, char const *argv[]) { // main function 
    ifstream inStream;

    string dataFileName; // string for the data file name 
    int lNumber;  // int type for license number
    int numViolations;  // variable to hold violationsNum function result 

    cout << "Enter the data file name: ";
    cin >> dataFileName;

    inStream.open(dataFileName.c_str()); // Open the file the user requested

    if (inStream.fail()){   //. Check to see if file exist and print error if it does not
        cout << "Error: file does not exist"<< endl;
       exit(1);
    }

    cout << "Enter the license number: ";  // Request License Number
    cin >> lNumber;

    if (lNumber < 0){ // Print invalid license number if the number is negative 
        cout << "Error: Invalid license number"<<endl;
       exit(1);
    }

    numViolations = violationsNum(inStream, lNumber); // Function call for violationsNum placing result in numViolatioms

    printResults(lNumber,numViolations);  // Call function that prints the results 
    

    inStream.close(); // close file 
    return 0;
}// main

// Function 1 to print the # of violations 
int violationsNum(ifstream &inStream, int licenseNum ){

    int violations = 0; // counter of violations 
    int lNumberRead = 0; // the license number read from file

    inStream >> lNumberRead;


    while (!inStream.eof()){ // Loop that reads the license num from user and goes until it reaches the end of file.
        

        if (licenseNum == lNumberRead){

            violations++;  // Increment violations by one if the lNumberRead matches licenseNUm
        }

       inStream >> lNumberRead;   // Read next number 

    }
    return violations;  // returns number of calculations 
}

void printResults(int licenseNum, int violations){ // Function to print results 

    cout << "Driver license "<< licenseNum << " has "<< violations<< " violations."<<endl;

    if (violations > 6){ // If it has greater than 6 violations  the license will be suspended

        cout << "Driver license "<< licenseNum << " should be suspended. "<< endl;
    }

}
