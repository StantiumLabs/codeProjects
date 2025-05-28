#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class Resistance {
	private:
		double resistance; 
		int tolerance;
		string band1, band2, band3, band4;
		ifstream inFile;
	public:
		Resistance(double, int);
		void Get_Standard_Resistance(double, int);
		void getResistance(double&, int&, string&, string&, string&, string&);	
		int getTolerance();
		double Rmax();
		double Rmin();
};




