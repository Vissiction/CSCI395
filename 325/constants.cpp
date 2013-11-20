/************************
* Will Connell
* Identifying Legal Pascal Real Constants
* Problem 213
************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string trim(string inString);	// Trims leading whitespace, returns resulting string
bool isLegal(string inString);	// True if inString is a legal Pascal real constant
bool isWhiteSpace(char inChar);	// True if inChar is a whitespace character
bool isNumber(char inChar);	// True if inChar is 0-9
bool isDecimal(char inChar);	// True if inChar is '.'
bool isSign(char inChar);	// True if inChar is '+' or '-'
bool isE(char inChar);		// True if inChar is 'e' or 'E'

main()
{
	string inString;

	getline(cin, inString);
	while(inString != "*")
	{
		inString = trim(inString);
		if(isLegal(inString))
			cout<<inString<<" is legal."<<endl;
		else
			cout<<inString<<" is illegal."<<endl;
		getline(cin, inString);
	}
}

string trim(string inString)
{
	// Trims all leading whitespace characters off of inString
	// Returns the resulting string
	string::iterator curr = inString.begin();

	while(curr != inString.end())
	{
		if(isWhiteSpace(*curr))
		{
			curr = inString.erase(curr);
		}
		else
		{
			break;
		}
	}

	curr = inString.end();
	curr--;

	while(curr != inString.begin())
	{
		if(isWhiteSpace(*curr))
		{
			curr =  inString.erase(curr);
		}
		else
		{
			break;
		}
	}

	return inString;
}

bool isLegal(string inString)
{
	// Returns true if inString is a legal Pascal Real Constant
	string::iterator curr = inString.begin();
	char prev = *curr;
	bool retVal = true;
	int decimalCount = 0;
	bool afterE = false;
	bool decimalInE = false;

	while(curr != inString.end() && retVal)
	{
		// Manage decimalCount
		if(afterE && isDecimal(*curr) && !decimalInE)
		{
			decimalInE = true;
			prev = *curr;
			curr++;
			continue;
		}
		else if(isDecimal(*curr))
			decimalCount++;
		if(decimalCount > 1)
			retVal = false;

		// Manage decimals in exponents
		if(isE(*curr))
			afterE = true;

		// Check for other disqualifiers
		if(curr == inString.begin())
		{
			// Can only start with a number or sign
			if(!isNumber(*curr) && !isSign(*curr))
				retVal = false;
		}
		else if(decimalInE)
		{
			// Decimals can only be ".000..."
			if(*curr != '0')
				retVal = false;
		}
		else if(isSign(*curr))
		{
			// Can only have a sign within the number if it's starting
			// an exponent
			if(!isE(prev))
				retVal = false;
		}
		else if(!isNumber(prev))
		{
			// Can't have two non-numbers in a row otherwise
			if(!isNumber(*curr))
				retVal = false;
		}

		prev = *curr;
		curr++;
	}

	// Must end with a number
	if(!isNumber(prev))
		retVal = false;
	// Must have a decimal or exponent in it
	if(decimalCount == 0 && !afterE)
		retVal = false;

	return retVal;
}

bool isWhiteSpace(char inChar)
{
	if(inChar == '\n' || inChar == '\r' || inChar == ' ' || inChar == '\t')
		return true;
	else
		return false;
}

bool isNumber(char inChar)
{
	if(inChar == '0' ||
		inChar == '1' ||
		inChar == '2' ||
		inChar == '3' ||
		inChar == '4' ||
		inChar == '5' ||
		inChar == '6' ||
		inChar == '7' ||
		inChar == '8' ||
		inChar == '9')
		return true;
	else
		return false;
}

bool isDecimal(char inChar)
{
	if(inChar == '.')
		return true;
	else
		return false;
}

bool isSign(char inChar)
{
	if(inChar == '+' || inChar == '-')
		return true;
	else
		return false;
}

bool isE(char inChar)
{
	if(inChar == 'e' || inChar == 'E')
		return true;
	else
		return false;
}
