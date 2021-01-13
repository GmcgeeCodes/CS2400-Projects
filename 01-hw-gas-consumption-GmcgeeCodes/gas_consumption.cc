/*
 *        File: gas_consumption.cc
 *      Author: Gerald McGee
 *        Date: 01/31/19
 * Description: Program to calculate gas consumption for driving in town and for driving on the highway
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {
   // step 1 1. Declare per gallon variables for town and Highway 
   double mpgT= 22.5;
   double mpgH = 29.5;

   //2 Get user input for miles driven in town & print gas consumpution for town driving 
   double townMiles;
   cout << "Enter the number of miles driven in town: " << endl;
   cin >> townMiles;

   //Gas Cons town 
   double gasConsTown;
   gasConsTown = townMiles/ mpgT;
   
   //2 Get user input for miles driven on highway & print gas consumption for highway driving
   double highwayMiles;
   cout  << "Enter the number of highway miles: "<< endl;
   cin >> highwayMiles; 

   //Gas Cons Highway 
   double gasConsHighway;
   gasConsHighway = highwayMiles / mpgH ; 

   //3 Total miles driven 
   double totalMiles;
   totalMiles = townMiles + highwayMiles;

   //4 total gas consumption
   double totalGasCons;
   totalGasCons = gasConsTown + gasConsHighway;

   //5 Average mpg for the trip 
   double averageMPG;
   averageMPG = totalMiles / totalGasCons;

   cout << "The number of miles driven in town: "<< townMiles << " miles" << endl;
   cout << "The gas consumption for town driving: "<< gasConsTown << " gallons" << endl;
   cout << "The number of miles driven on the highway: " << highwayMiles << " miles" << endl;
   cout << "The gas consumption for highway driving "  << gasConsHighway << " gallons" << endl;
   cout << "The total miles driven: " << totalMiles << " miles" << endl;
   cout << "The total gas consumption: "<< totalGasCons << " gallons" << endl;
   cout << "The average mpg for the trip:  "<<  averageMPG << " miles/gallon"<< endl;

   return 0;
}// main
