/*********************
* Will Connell
* Just used to count the number
* of binary strings that 
* binaryprinter made, to help initialize
* the array
******************* */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

main()
{
	string instring;
	int count = 0;

	fstream infile;
	infile.open("binary.txt", ios::in);

	while(!infile.eof())
	{
		infile>>instring;
		count++;
	}

	cout<<count<<endl;
}
