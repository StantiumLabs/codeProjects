#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "Resistance.h"

using namespace std;

//constructor 

Resistance::Resistance(double R, int T) {
    tolerance = T;
    Get_Standard_Resistance(R, T);
}

void Resistance::Get_Standard_Resistance(double R, int T) {
	
	//Temporary variables not included in class
        
    double closestResistance = -1;
    int diff1 = 10000, tdiff;
    string tband1,tband2,tband3,tband4;

    if (T == 5)
        inFile.open("Resistors_5_Percent.txt");
    else if (T == 10)
        inFile.open("Resistors_10_Percent.txt");
    else
        inFile.open("Resistors_20_Percent.txt");
    
//To get to the "closest resistance value", I implemented a max difference logic.  I assumed the user wouldn't
//the largest possible difference was 10000
        
	while(inFile >> resistance >> band1 >> band2 >> band3 >> band4) {
		tdiff = abs(R-resistance);
		
		if(tdiff<diff1) {
			diff1 = tdiff;
			closestResistance = resistance;
			tband1 = band1;
			tband2 = band2;
			tband3 = band3;
			tband4 = band4;
		}}
		
		resistance = closestResistance;
		band1 = tband1;
		band2 = tband2;
		band3 = tband3;
		band4 = tband4;

	inFile.close();
}


void Resistance::getResistance(double &res, int &tol, string& b1, string& b2, string& b3, string& b4) {
	res = resistance;
	tol = tolerance;
	b1 = band1;
	b2 = band2;
	b3 = band3;
	b4 = band4;
}

int Resistance::getTolerance(){
	return tolerance;
}

//The maximum resistance within tolerance ex: if entered resistance is 3300 with a 10%
//tolerance, then Rmax should return 3630
double Resistance::Rmax() {
	double maxRes = resistance + resistance*tolerance/100;
	return maxRes; 
}

//The minimum resistance within tolerance ex: if entered resistance is 3300 with a 10%
//tolderance, then Rmin should be 2970
double Resistance::Rmin() {
	double minRes = resistance - resistance*tolerance/100;
	return minRes;
}
		


