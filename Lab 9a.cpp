/*
Programmer: Drew Welbourn
Lab: 9a
Purpose: Payroll
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

double paid(int, double, double);





int main()
{

	string name;
	int hours = 0;
	double rate = 0, pay = 0, ot = 0, gross = 0;
	ifstream infile;

	infile.open("C:\\Users\\Drew\\Desktop\\Rates.txt");


	// Test if file opens correctly; if not EXTERMINATE

	if (infile.fail())
	{
		cout << "The input file did not open correctly.";
		exit(1);
	}

	cout << fixed << showpoint << setprecision(2);

	cout << setw(12) << "Name" <<
		setw(10) << "Rate" <<
		setw(10) << "Hours" <<
		setw(8) << "Pay" << 
		setw(12) << "Over Time" <<
		setw(8) << "Gross"<< endl;

	//Read from the file until it reaches end of the file

	while (!infile.eof())
	{
		infile >> name >> rate >> hours;
		ot = paid(hours, rate, ot);
		pay = rate * hours;
		gross = pay + ot;

		cout << setw(12) << name <<
			setw(10) << rate <<
			setw(10) << hours <<
			setw(10) << pay <<
			setw(10) << ot <<
			setw(10) << gross << endl;

	}

	infile.close();

	return 0;
}

double paid(int hours, double rate, double ot)
{


	{
		if (hours > 40)
			ot = ((rate * 1.5) * (hours % 40));
		else
			ot = 0;
	}


	return ot;
}