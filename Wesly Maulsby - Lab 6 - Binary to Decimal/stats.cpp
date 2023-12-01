#include "stats.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//constructor
Stats::Stats()
{
}

//destructor
Stats::~Stats()
{
}

int Stats::binaryConversion()
{
	//infile
	string inputFileName = "BinaryIn.dat";

	//output header
	cout << "Binary Input                                               ||  Decimal Output   \n";
	// 13 11 15
	ifstream infile;
	infile.open(inputFileName);

	//initializes values
	char input;
	int base10 = 0;
	bool firstDigit = false;
	int count = 0;
	bool badDigit = false;
	int spaces = 0;
	string space = " ";

	infile.get(input);

	//reads input digit by digit for binary conversion
	while (infile)
	{
		while (input != '\n' && infile)
		{
			if (!firstDigit && input == '1' || firstDigit && (input == '1' || input == '0'))
			{
				//binary conversion
				spaces = spaces + 1;
				count++;
				cout << input;
				firstDigit = true;
				base10 *= 2;

				if (input == '1')
				{
					base10++;
				}
			} //bad digit on input check
			else if (input != ' ' || input == ' ' && firstDigit)
			{
				for (int i = 0; i < count; i++)
					cout << '\b';
				cout << "bad digit on input                                         ||\n";
				badDigit = true;
				infile.ignore(256, '\n');
				break;
			}
			infile.get(input);
		}
		//if number is valid then it outputs the answer
		if (!badDigit)
			for (int i = 0; i < spaces; i++)
			{
				//spaces after binary input
				cout << "                                                           ";
				//should loop for the amout of times that a number was read in for a binary input, stored in "spaces"
				while (spaces > 0)
				{
					cout << "\b";
					spaces = spaces - 1;
				}
				//outputs the rest of the output
				cout << "||  " << base10 << endl;

			}		//resets variables for next input
		firstDigit = false;
		badDigit = false;
		count = 0;
		infile.get(input);
		base10 = 0;
		spaces = 0;
	}



	return 0;
}