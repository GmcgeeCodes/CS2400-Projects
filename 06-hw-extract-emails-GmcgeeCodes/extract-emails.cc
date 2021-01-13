/*
 *        File: extract-emails.cc
 *      Author: Gerald McGee
 *        Date: 4/10/19
 * Description: This program is able to derive the email, username, and domain of someone by processing an html file. The program also prints
 * the number of lines processed and the number of emails found to the user. The program achieves this by finding the emails in a line and splitting 
 * that email address into a username and domain part. Only unique emails are outputted to the file by using the outputData function. The user names, domains, and emails
 * are all stored in vectors os strings.
 * 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

//function prototypes
void getLineEmails(string input, vector <string> &emails, vector <string> &user, vector <string> &domain);
/*
 * The purpose of this function is to find and derive the emails in each line. It takes the string from the getline
 * function and a vector of emails. It also takes a vector of users and domains to pass to the splitEmailAddress function.
*/
void splitEmailAddress(string email, vector <string> &user, vector <string> &domain);
/*
 * The purpose of this function is to split the email found from the getLineEmails function into two parts.
 * A domain and user string to input it into their respective vectors of strings. The string this function takes is
 * an email produced by the getLineEmails function.
 * 
*/
void outputData(const vector <string> &email, const vector <string> &user, const vector <string> &domain, string outputFile);
/*
 * The purpose of this function is to output the data found about the employee's information to the
 * output file. This function takes the vectors of email, user, and domain to simply print to the file.
 * The string parameter is the name of the output file the user wants the results in.
*/
int search (const vector <string> &emails, string target);
/*
 * The purpose of this function is to search if the email found is in the vector of emails already before
 * placing that email into the vector of strings, and calling the splitEmailAddress function. It takes the vector 
 * of emails and a target string to find the target.
*/

int main(int argc, char const *argv[]) {
	ifstream inStream; // Open input file 

	if (argc > 3){
		cout <<"Error: too many files provided." << endl;
		exit(1);

	}
	if (argc < 3){
		cout <<"Error: not enough information provided." << endl;
		exit(1);
    }

	string inputFile = argv[1]; // Setting input file to the index one of argv
	string outputFile = argv[2]; // Setting output file to index two of argv

	inStream.open(inputFile.c_str());

	if(inStream.fail()){ // Check for failure
		cout << "Error: Input file not found!" << endl;
		exit(1);
	}

	string inputLine = ""; // Empty string to put strings from file into.
	vector <string> emails; // Declaration of three vectors for emails, user, and domain.
	vector <string> user;
	vector <string> domain;

	int linesProcessed = 0; // Counts lines processed 
	while(!(inStream.eof())){ 

	getline(inStream, inputLine);
	linesProcessed++;
	getLineEmails(inputLine, emails, user, domain);

	}
	outputData(emails, user, domain,outputFile);

	cout << linesProcessed <<" lines "<<"processed"<< endl;
	cout << emails.size()  <<" emails "<<"found"<< endl;


	inStream.close();
	return 0;
}// main

void getLineEmails(string input, vector <string> &emails, vector <string> &user, vector <string> &domain){ // Function to get the unique emails in each line

	int mainLength = input.length();

	string target = "mailto:";
	int subLength = target.length();

	int occurences = 0;

	for (int i = 0; i < mainLength; i++){
		if (input.substr(i, subLength) == target){
			occurences++; 
		}
	}

	int location = 0; // Variable to track where I am in the string. 
	string email = "";

	for(int i = 0; i < occurences; i++){

		location = input.find("mailto:", location); 

		int emailIndexOne = location + 7;

		location = input.find(">", emailIndexOne);

		int emailIndexTwo = location - 1; 

		int emailLength = emailIndexTwo - emailIndexOne;

		 email = input.substr(emailIndexOne, emailLength);

		if (search(emails, email) == -1){

			emails.push_back(email); // Put email in next available position
			splitEmailAddress(email, user, domain); // Call function to split unique email address.

		}

	}
}
int search(const vector <string> &emails, string target){ // Function to search for email addresses that are unique
	for (size_t i = 0; i < emails.size(); i++){
		if (target == emails[i]){
			return i;
		}
	}
	return -1;
}
void splitEmailAddress(string email, vector <string> &user, vector <string> &domain){ // Function to split email address into username and domain
	int atLocation = email.find("@");
	int emailSize = email.length();
	int firstIndex = atLocation;

	string userName = email.substr(0, atLocation);

	int domainLength = emailSize - firstIndex;

	string domainName = email.substr(atLocation, domainLength);

	user.push_back(userName); //Putting the username and domain in the next available positions.
	domain.push_back(domainName);

}
void outputData( const vector <string> &email,const vector <string> &user,const vector <string> &domain, string outputFile){
	ofstream outStream; //Output stream declaration

	outStream.open(outputFile.c_str());

	if(outStream.fail()){ // Check for failure 
		cout <<"Error: output file does not exist."<< endl;
		exit(1);
	}
	//Output results to file
	outStream << left << setw(25) << "Email";
	outStream << setw(10) << "user";
	outStream << setw(5) <<"domain"<< endl;
	outStream <<"--------------------------------------------"<< endl;

	for (int i = 0; i < email.size() ;i++){

		outStream << setw(25) << email[i];
		outStream << setw(10) << user[i];
		outStream << setw(5) << domain[i];
		outStream << endl;
	}

     outStream.close(); // close file 
}