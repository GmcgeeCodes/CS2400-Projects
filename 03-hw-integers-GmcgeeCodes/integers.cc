
/*
 *        File: integers.cc
 *      Author: Gerald McGee
 *        Date: 2/21/19
 * 
 * Description: Program that takes integers and finds the number of digits, a specific digit in a number, finds the sum of all digits
 * and is able to tell if an integer is a palindrome or not. The program also contains a function getInteger() that will keep on asking the user
 * for a positive integer until it is given. The menuDisplay(); function is a void function that keeps on printing the menu of choices when it is needed.
 * Lastly, the function quits by entering a 5 for the choice which is the sentinel value for the while loop the program is run through.
 * 
 * 
 * 
 */ 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath> 



using namespace std;

//function prototypes
int getSumDigits(int number);
int getNumDigits (int number);
int getInteger();
int getNthDigit(int number, int n);
bool isPalindrome(int number);
void menuDisplay();

int main(int argc, char const *argv[]) {  // Main function
    int choice;    // The menu choice of the user 

    menuDisplay();  // Function call to display menu 
    cin >> choice;

    while (choice != 5)  // Sentinel While loop so the program quits when user enters 5 
    {
        
       if (choice >= 1 && choice <= 5) {  //used to be less than or equal 5 // menu in each switch
            //switch statement 

            switch (choice) {

                case 1:  // start of case 1/ Corresponds with Function 1 

                int number;    //positive Integer for Function 1
                cout << "Enter a positive integer: ";
                cin >> number;

                if (number < 0){  // If statement to check for negative input on number

                    number = getInteger();  // Function call for get integer 
                }
                   cout << endl;                     
                   cout << number << " has "<< getNumDigits(number) << " digits" << endl;        // This prints the number of digits           

                    menuDisplay();  // This function prints menu 
                    cin >> choice;

                break; // end of case 1 

                case 2:

                    int numberTwo;  // integer number for case 2/ function 2
                    int digitNthPos;   // the nth Position the user inputs 
                    int digitPosResult; // digit position result 

                    cout <<"Enter an integer number: ";
                    cin >> numberTwo;

                    if (numberTwo < 0 ) {

                      //  numberTwo = F1Integer;
                        numberTwo = getInteger();

                    }
                    //////
                    cout <<"Enter a position: ";  // These next few lines get the position and check it for a negative 
                    cin >> digitNthPos;

                    if (digitNthPos < 0) {

                        while (digitNthPos < 0){

                            cout <<"Enter a position: ";
                            cin >> digitNthPos;
                        }

                     
                    }

                    if (getNumDigits(numberTwo) <  digitNthPos){  // If the number of digits in the number is less than nth position, its invalid 

                        cout << "Invalid position" << endl;

                    } else {  // Print the value of the nth Position of number 

                        digitPosResult = getNthDigit(numberTwo, digitNthPos);
                        cout << endl;  
                        cout << "Digit number "<< digitNthPos <<" is "<< digitPosResult << endl; // Print n position  is the digit position result 
                    }       

                    menuDisplay();  
                    cin >> choice; 
                break;  //end of case 2

                case 3:
                int numberThree;  // Number Three int for function/ case 3
            
                cout << "Enter an integer number: "; 
                cin >> numberThree;

                if (numberThree < 0){ // Check for negative and call function to get pos
           
                     numberThree = getInteger();
                    
                }

                cout <<" The sum of all digits in "<< numberThree <<" is " << getSumDigits(numberThree) << endl;


                    menuDisplay();
                    cin >> choice;

                break; // end of case 3 

                case 4:

                int pDrome;  // intger for palindrome function 
                bool x; // True or false value returned from function.

                cout << "Enter an integer number: ";
                cin >> pDrome;

                if (pDrome < 0){

                    pDrome = getInteger();
                }

                x = isPalindrome(pDrome); // x = value of palindrome function

                if (x == true){ // These next lines print either a palindrome or not a palindrome 

                    cout << "The number "<< pDrome << " is a palindrome"<< endl;
                }
                else if (x == false) {

                    cout << "the number "<< pDrome << " is not a palindrome. "<< endl;
                }

                   menuDisplay();
                   cin >> choice;

                break; // end of case 4      
            }

        } else {  // beginning of else statement 

             cout << "Invalid Choice, Please choose one of the options again."<< endl; // Prints invalid choice if choice isn't correct 
            

            menuDisplay();
             cin >> choice;

        } // else statement end 
   
    }

    cout << "Done!" << endl; // Prints done when user enters 5 before quit

         return 0;       
}

int getSumDigits(int number){ // Function to get sum of all digits 

int numberSum = 0;
int y; 

while (number > 0){

    y = number % 10;
    numberSum = numberSum + y;
    number = number / 10; 

}
return numberSum;

}
   

int getNumDigits (int number) {  //getNumDigits Function for option #1 to get the number of digits 

    int numDigits=0;

    while (number != 0){
        number = number/10;
        numDigits++;
    }

    return numDigits;
}


int getInteger() {  // Function that gets positive integer 

    int posNum = 0;
  
    do {

        cout << "Enter a positive integer: "; 
        cin >> posNum;   
        
    } while (posNum < 0); 

    return posNum; 
    }

    int getNthDigit (int number, int n){ // Function for option #2 that gets nth digit 

        int x = number;             // the number the user entered.
        int power = n - 1;           // Subtract what the user entered minus one
        int placeValue = pow(10,power);   // 10 to the n-1 stored in power
        int preMod = x / placeValue;    // The number / the place value which is 10 to the power
        int localDigitPosResult = preMod % 10; // Final Result for digit position 

        return localDigitPosResult;
    }

    bool isPalindrome(int number){  // Function to see if a number is a palindrome or not 
       
        int rightDigitHE = getNumDigits(number);
        int leftDigitLE = 1; 

        if (getNthDigit(number,leftDigitLE) != getNthDigit(number,rightDigitHE)){

            do {
                leftDigitLE++;
                rightDigitHE--; 

        
            }while (leftDigitLE == rightDigitHE);

            return false;
        }

        return true; 
    }
  

    void menuDisplay(){  // Function that displays menu 
        cout << endl; 
        cout << "1. Find the number of digits in an integer."<< endl;
        cout << "2. Find the nth digit in an integer."<< endl;
        cout << "3. Find the sum of all digits of an integer."<< endl;
        cout << "4. Is the integer a palindrome?"<< endl;
        cout << "5. Quit"<< endl;
        cout <<"Enter a choice: ";  
    }
   

    









    
    

