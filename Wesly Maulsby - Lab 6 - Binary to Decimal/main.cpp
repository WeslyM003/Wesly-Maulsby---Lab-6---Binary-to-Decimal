#include <iostream>
#include <fstream>

using namespace std;

string inputFileName = "BinaryIn.dat";

int main()
{
	cout << "Binary Input                                                    ||  Decimal Output   \n";
	// 13 11 15
	ifstream infile;
	infile.open(inputFileName);

	char input;
	int base10 = 0;
	bool firstDigit = false;
	int count = 0;
	bool badDigit = false;
	int spaces = 0;
	string space = " ";

	infile.get(input);
	
	while (infile)
	{
		while (input != '\n' && infile)
		{
			if (!firstDigit && input == '1' || firstDigit && (input == '1' || input == '0'))
			{
				spaces = spaces + 1;
				count++;
				cout << input;
				firstDigit = true;
				base10 *= 2;

				if (input == '1')
				{
					base10++;
				}
			}
			else if (input != ' ' || input == ' ' && firstDigit)
			{
				for (int i = 0; i < count; i++)
					cout << '\b';
				cout << "bad digit on input                                              ||\n";
				badDigit = true;
				infile.ignore(256, '\n');
				break;
			}
			infile.get(input);
		}
		
		if (!badDigit)
			for (int i = 0; i < spaces; i++)
				space += '\b';
			cout << "                                                           " << space << "||  " << base10 << endl;
		firstDigit = false;
		badDigit = false;
		count = 0;
		infile.get(input);
		base10 = 0;
		spaces = 0;
	}



	return 0;
}