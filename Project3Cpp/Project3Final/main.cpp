//       ____   __     __
//        /   /   \  /   \
//       /   /      /
//      /    \___/  \___/
//
// Date: 23APR25
// Name: Adrian Stanton
// Project Description: Project #3 Resistor Color Code Class | The class was tasked with utilizing the fstream
// 						preprocessor directive and the class structure to create a class called "Resistance"
//						and assign it values based on the user input of resistance and tolerance.
// Inputs: Desired Resistance and tolerance values
// Outputs:	The closest standard resistance value, max resistance within desired tolerance, minimum resistance
//          within desired tolerance.  
//*************************************************************

#include <iostream>
#include <string>
#include "Resistance.h"

using namespace std; 

int main ()
{
	double userRes;
	int userTol;
	string col1, col2, col3, col4;
	
	while (userRes != -1 || userTol != -1) {
		if(userTol == -1)
			break;
		cout << "Enter -1 to exit program...\n";
		cout << "Please enter the desired resistance value in ohms: ";
		cin >> userRes;
		if(userRes == -1)
			break;
		while(userRes < 10 || userRes == 0 || userRes > 1000000) {
			cout << "Please enter a valid resistance value.  Values must be between 10 and 1,000,000 ohms, and \n"
				 << "must be positive: ";
			cin >> userRes;
		}
		cout << "\nPlease enter the desired tolerance as a percentage (5,10, or 20): ";
		cin >> userTol;
		cout << endl;
		while(userTol != 5 && userTol !=10 && userTol != 20 && userTol != -1) {
			cout << "Please enter a valid tolerance value.  Values must be either 5, 10, or 20: "
				 << endl;
			cin >> userTol;
		}
	
		Resistance userValue(userRes, userTol);
		userValue.getResistance(userRes, userTol, col1, col2, col3, col4);
		
		cout << "Closest standard value is: " << userRes << " ohms" << endl
			 << "Color band A: " << col1 << endl
			 << "Color band B: " << col2 << endl
			 << "Color band C: " << col3 << endl
			 << "Color band D: " << col4 << endl << endl;
			 
		cout << "The max resistance with a " << userValue.getTolerance() << "% tolerance is: "
			 << userValue.Rmax() << endl;
			 
		cout << "The minimum resistance with a " << userValue.getTolerance() << "% tolerance is: "
			 << userValue.Rmin() << endl << endl;
			 
	}

    return 0;
}
