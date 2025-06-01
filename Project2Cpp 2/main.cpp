//       ____   __     __
//        /   /   \  /   \
//       /   /      /
//      /    \___/  \___/
//
// Date: 03APR2025
// Name: Adrian Stanton
// Project Description: This program allows the user to create tables of voume and area
// 		as radius or height varies for some common solids.  Three solids will be considered
//		in this program: cylinder, cone, and ellipsoid. 
// Inputs: Radius, Height, Start Point, End Point, Increment
// Outputs: Area/Volume with incremented value in table format
//*************************************************************

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double areaCyl(double, double);
double volCyl(double, double);
double areaCone(double, double);
double volCone(double, double);
double areaLip(double, double, double);
double volLip(double, double, double);

int main() {
    int userChoice,factor = 1000, intStart, intEnd, intIncrement, col1, col2, col3;
    double userRadius, userHeight, userStart, userEnd, increment, userRada, userRadb, userRadc, idouble, numLines=0;
    string userUnitChoice, inputSwitch;
    char userUnitChoiceChar;
    bool userUnitChoiceSat = false;
    
    cout << "This program produces different tables of values based on user input. \n"
         << "Option 1: Cylinder with fixed height as radius varies. \n"
         << "Option 2: Cylinder with fixed radius as height varies. \n"
         << "Option 3: Cone with fixed height as radius varies. \n"
         << "Option 4: Cone with fixed radius as height varies. \n"
         << "Option 5: Ellipsoid with fixed radius a and b as radius c varies. \n"
         << "Option 0: Terminate Program" << endl << endl;
    
    do {
    cout << "\nPlease enter values of 1 - 5: ";
    cin >> userChoice;
    
        while (userChoice > 5 || userChoice < 0) {
            cout << "\nPlease enter a valid option: ";
            cin >> userChoice;
        }
        
    if(userChoice != 0) {
    	
    do {
        cout << "\nPlease enter the desired units in the form i or I for inches, f or F for feet, \n"
             << "m or M for meters, and c or C for centimeters: ";
        cin >> inputSwitch;
        cout << endl;
        
        if (inputSwitch.length() != 1) {
        	cout << "\nPlease enter only a single character representing the unit." << endl << endl;
        	continue;
		}
        
   		userUnitChoiceChar = inputSwitch[0];
        switch(userUnitChoiceChar) {
            case 'I':
            case 'i':
                userUnitChoice = "in";
                userUnitChoiceSat = true;
                break;
            case 'F':
            case 'f':
                userUnitChoice = "ft";
                userUnitChoiceSat = true;
                break;
            case 'm':
            case 'M':
                userUnitChoice = "m";
                userUnitChoiceSat = true;  
                break;
            case 'C':
            case 'c':
                userUnitChoice = "cm";
                userUnitChoiceSat = true;
                break;
            default: 
                cout << "Please enter a valid unit: " << endl;
                break;
        }
        if (userUnitChoiceSat == true) {
        cout << endl << "Please enter # of digits after the decimal point to be displayed in Column 1: ";
        cin >> col1;
        cout << endl << "Please enter # of digits after the decimal point to be displayed in Column 2: ";
        cin >> col2;
        cout << endl << "Please enter # of digits after the decimal point to be displayed in Column 3: ";
        cin >> col3;
        
        while (col1 > 7 || col1 < 0 || col2 > 7 || col2 < 0 || col3 > 7 || col3 < 0) {
        	cout << endl << "Number of digits after the decimal must be greater than 0 and less than or equal to 6.  \nPlease Try Again..";
        	cout << endl << "Please enter # of digits after the decimal point to be displayed in Column 1: ";
        	cin >> col1;
        	cout << endl << "Please enter # of digits after the decimal point to be displayed in Column 2: ";
        	cin >> col2;
        	cout << endl << "Please enter # of digits after the decimal point to be displayed in Column 3: ";
        	cin >> col3;
		}
	}
    } while (!userUnitChoiceSat);
}
   
        
    switch(userChoice) {
    	
        case 1: 
            cout << endl << "Please enter the fixed height for a cylinder: ";
            cin >> userHeight;
            cout << "\nPlease enter the starting radius, ending radius, and the increment: ";
            cin >> userStart >> userEnd >> increment;
            
			
        	numLines = ((userEnd - userStart) / increment) + 1;    
            while (numLines <3 || numLines > 25) {
                numLines = 0;
                cout << "The number of lines allowed for this program is between 3 and 25.  Please reenter the starting point, ending point, and increment: ";
                cin >> userStart >> userEnd >> increment;			
        		numLines = ((userEnd - userStart) / increment) + 1;
                cout << "Number of Lines: " << numLines << endl;
                cout << "Number of lines SAT" << endl;
            }

            
            while (userStart <= 0 || userEnd <=0 || increment <=0) {
                cout << "\nInvalid input.  Starting point, ending point, and increment must be greater than 0."
                     << "Please input values again: ";
                cin >> userStart >> userEnd >> increment;
            }
            
                
        		intStart = static_cast<int>(userStart * factor);
        		intEnd = static_cast<int>(userEnd * factor);
        		intIncrement = static_cast<int>(increment * factor);
            
            cout << endl << "Area and Volume of a Cylinder With Fixed Height \nHeight = " << userHeight << " as Radius varies" << endl << endl
                 << "Radius(" << userUnitChoice << ")" << setw(10) << "Area(" << userUnitChoice << "^2)" << setw(13)
                 << "Volume(" << userUnitChoice << "^3)" << endl;
                
            for(int i = intStart; i <= intEnd; i += intIncrement) {
            	idouble = static_cast<double>(i) / factor;
                cout << fixed
			         << setprecision(col1) << setw(8)  << right << idouble
					 << setprecision(col2) << setw(15) << right << areaCyl(idouble, userHeight)
					 << setprecision(col3) << setw(15) << right << volCyl(idouble, userHeight) << endl;
            }
            break;
            
            
        case 2:
            cout << endl << "Please enter the fixed radius for a cylinder: ";
            cin >> userRadius;
            cout << "\nPlease enter the starting height, ending height, and the increment: ";
            cin >> userStart >> userEnd >> increment;

        	numLines = ((userEnd - userStart) / increment) + 1;    
            while (numLines <3 || numLines > 25) {
                numLines = 0;
                cout << "The number of lines allowed for this program is between 3 and 25.  Please reenter the starting point, ending point, and increment: ";
                cin >> userStart >> userEnd >> increment;			
        		numLines = ((userEnd - userStart) / increment) + 1;
                cout << "Number of Lines: " << numLines << endl;
                cout << "Number of lines SAT" << endl;
            }

            
            while (userStart <= 0 || userEnd <=0 || increment <=0) {
                cout << "\nInvalid input.  Starting point, ending point, and increment must be greater than 0."
                     << "Please input values again: ";
                cin >> userStart >> userEnd >> increment;
            }
            
                
        		intStart = static_cast<int>(userStart * factor);
        		intEnd = static_cast<int>(userEnd * factor);
        		intIncrement = static_cast<int>(increment * factor);
            
            cout << endl << "Area and Volume of a Cylinder With Fixed Radius \nRadius = " << userRadius << " as Height varies" << endl << endl
                << "Height(" << userUnitChoice << ")" << setw(10) << "Area(" << userUnitChoice << "^2)" << setw(13)
                << "Volume(" << userUnitChoice << "^3)" << endl;
                
            for(int i = intStart; i <= intEnd; i += intIncrement) {
            	idouble = static_cast<double>(i) / factor;
                cout << fixed 
				     << setprecision(col1) << setw(8) << right << idouble 
					 << setprecision(col2) << setw(15) << right << areaCyl(userRadius, idouble)
					 << setprecision(col3) << setw(15) << right << volCyl(userRadius, idouble) << endl;
            }
            break;
            
            
        case 3:
            cout << endl << "Please enter the fixed height for a cone: ";
            cin >> userHeight;
            cout << "\nPlease enter the starting radius, ending radius, and the increment: ";
            cin >> userStart >> userEnd >> increment;
    
        	numLines = ((userEnd - userStart) / increment) + 1;    
            while (numLines <3 || numLines > 25) {
                numLines = 0;
                cout << "The number of lines allowed for this program is between 3 and 25.  Please reenter the starting point, ending point, and increment: ";
                cin >> userStart >> userEnd >> increment;			
        		numLines = ((userEnd - userStart) / increment) + 1;
                cout << "Number of Lines: " << numLines << endl;
                cout << "Number of lines SAT" << endl;
            }

            
            while (userStart <= 0 || userEnd <=0 || increment <=0) {
                cout << "\nInvalid input.  Starting point, ending point, and increment must be greater than 0."
                     << "Please input values again: ";
                cin >> userStart >> userEnd >> increment;
            }
            
                
        		intStart = static_cast<int>(userStart * factor);
        		intEnd = static_cast<int>(userEnd * factor);
        		intIncrement = static_cast<int>(increment * factor);
            
            cout << endl << "Area and Volume of a Cone With Fixed Height \nHeight = " << userHeight << " as Radius varies" << endl << endl
                << "Radius(" << userUnitChoice << ")" << setw(10) << "Area(" << userUnitChoice << "^2)" << setw(13)
                << "Volume(" << userUnitChoice << "^3)" << endl;
                
            for(int i = intStart; i <= intEnd; i += intIncrement) {
            	idouble = static_cast<double>(i) / factor;
                cout << fixed
				<< setprecision(col1) << setw(8) << right << idouble 
				<< setprecision(col2) << setw(15) << right << areaCone(idouble, userHeight) 
				<< setprecision(col3) << setw(15) << right << volCone(idouble, userHeight) << endl;
            }
            break;
            
            
        case 4:
            cout << endl << "Please enter the fixed radius for a cone: ";
            cin >> userRadius;
            cout << "\nPlease enter the starting height, ending height, and the increment: ";
            cin >> userStart >> userEnd >> increment;   
    
        	numLines = ((userEnd - userStart) / increment) + 1;    
            while (numLines <3 || numLines > 25) {
                numLines = 0;
                cout << "The number of lines allowed for this program is between 3 and 25.  Please reenter the starting point, ending point, and increment: ";
                cin >> userStart >> userEnd >> increment;			
        		numLines = ((userEnd - userStart) / increment) + 1;
                cout << "Number of Lines: " << numLines << endl;
                cout << "Number of lines SAT" << endl;
            }

            
            while (userStart <= 0 || userEnd <=0 || increment <=0) {
                cout << "\nInvalid input.  Starting point, ending point, and increment must be greater than 0."
                     << "Please input values again: ";
                cin >> userStart >> userEnd >> increment;
            }
            
                
        		intStart = static_cast<int>(userStart * factor);
        		intEnd = static_cast<int>(userEnd * factor);
        		intIncrement = static_cast<int>(increment * factor);
            
            cout << endl << "Area and Volume of a Cone With Fixed Radius \nRadius = " << userRadius << " as Height varies" << endl << endl
                << "Height(" << userUnitChoice << ")" << setw(10) << "Area(" << userUnitChoice << "^2)" << setw(13)
                << "Volume(" << userUnitChoice << "^3)" << endl;
                
            for(int i = intStart; i <= intEnd; i += intIncrement) {
            	idouble = static_cast<double>(i) / factor;
                cout << fixed
					 << setprecision(col1) << setw(8) << right << idouble
					 << setprecision(col2) << setw(15) << right << areaCone(userRadius, idouble)
					 << setprecision(col3) << setw(15) << right << volCone(userRadius, idouble) << endl;
            }
            break;
            
            
        case 5:
            cout << endl << "Please enter radius a: ";
            cin >> userRada;
            cout << "Please enter radius b: ";
            cin >> userRadb;
            cout << "Please enter the starting radius, ending radius, and the increment for radius C: ";
            cin >> userStart >> userEnd >> increment; 
    
        	numLines = ((userEnd - userStart) / increment) + 1;    
            while (numLines <3 || numLines > 25) {
                numLines = 0;
                cout << "The number of lines allowed for this program is between 3 and 25.  Please reenter the starting point, ending point, and increment: ";
                cin >> userStart >> userEnd >> increment;			
        		numLines = ((userEnd - userStart) / increment) + 1;
                cout << "Number of Lines: " << numLines << endl;
                cout << "Number of lines SAT" << endl;
            }

            
            while (userStart <= 0 || userEnd <=0 || increment <=0) {
                cout << "\nInvalid input.  Starting point, ending point, and increment must be greater than 0."
                     << "Please input values again: ";
                cin >> userStart >> userEnd >> increment;
            }
            
                
        		intStart = static_cast<int>(userStart * factor);
        		intEnd = static_cast<int>(userEnd * factor);
        		intIncrement = static_cast<int>(increment * factor);
            
            cout << endl << "Area and Volume of an Ellipsoid as Radius C Varies"
                 << endl << "Radius a = " << userRada << setw(8) << " Radius b = " << userRadb
                 << endl << endl << "Radius C(" << userUnitChoice << ")" << setw(10) << "Area(" << userUnitChoice << "^2)" << setw(13)
                 << "Volume(" << userUnitChoice << "^3)" << endl;
                 
                 for(int i = intStart; i <= intEnd; i += intIncrement) {
            	     idouble = static_cast<double>(i) / factor;
                     cout << fixed 
					 << setprecision(col1) << setw(10) << right << idouble 
					 << setprecision(col2) << setw(15) << right << areaLip(userRada, userRadb, idouble)
					 << setprecision(col3) << setw(15) << right << volLip(userRada, userRadb,idouble) << endl;
                 }
                               
            break;
    }
    if (userChoice == 0) {
    	cout << "\nProgram Terminated";
    	return 0;
	}
    cout << endl << endl
		 << "Option 1: Cylinder with fixed height as radius varies. \n"
         << "Option 2: Cylinder with fixed radius as height varies. \n"
         << "Option 3: Cone with fixed height as radius varies. \n"
         << "Option 4: Cone with fixed radius as height varies. \n"
         << "Option 5: Ellipsoid with fixed radius a and b as radius c varies. \n"
         << "Option 0: Terminate Program" << endl << endl;
    
    } while(userChoice != 0);
    
    
    return 0;
}

// areaCyl calculates the area of a cylinder with inputs of height and radius and output of area. 
double areaCyl(double radius, double height) {
    double area = 2*acos(-1.0)*radius*height;
    return area;
}
// volCyl calculates the volume of a cylinder with inputs of radius and height and output of volume.
double volCyl(double radius, double height){
    double volume = acos(-1.0) * radius * radius * height;
    return volume;
}
// areaCone calculates the area of a cone with inputs radius and height and output of area. 
double areaCone(double radius, double height){
    double area = acos(-1.0)*radius*sqrt(radius*radius+height*height);
    return area;
}
// volCone calculates the volume of a cone with inputs of radius and height and output of volume.  
double volCone(double radius, double height){
    double volume = (1.0/3)*acos(-1.0)*radius*radius*height;
    return volume;
}
// areaLip calculates the area of an ellipsoid with inputs of radii a, b, and c with outputs of area.
double areaLip(double rada, double radb, double radc){
    double area, fraction;
    fraction = pow(rada*radb,1.6) + pow(rada*radc,1.6) + pow(radb*radc,1.6);
    area = 4*acos(-1.0)*pow(fraction/3.0,1.0/1.6);
    return area;
}
// volLip calculates the volume of an ellipsoid with inputs of radii a, b, and c with outputs of volume.  
double volLip(double rada, double radb, double radc){
    double volume = 4/3.0 * acos(-1.0) * rada * radb * radc;
    return volume;
}
/* Didn't save any lines of code
bool isValidInput(double userStart, double userEnd, double increment, int userSetDec) {
    return !(userStart <= 0 || userEnd <= 0 || increment <= 0 || userSetDec <= 0 || userSetDec > 5);
}*/

