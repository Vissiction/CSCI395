/********************
* Will Connell
* Solution to 120
* Stacks of Flapjacks
* Not working
********************/

#include <iostream>
#include <iomanip>
#include <list>
#include <sstream>

using namespace std;

main() {
	string inLine;
	string outLine;
	stringstream converter;
	int inSize;
	list<int> stack;

	// Read first stack of pancakes
	getline(cin, inLine);
	converter.str(inLine);
	while(!converter.eof()) {
		converter >> inSize;
		stack.push_back(inSize);
	}

	while(!cin.eof()) {
		// Echo the stack
		for(list<int>::iterator it = stack.begin(); it != stack.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;

		/*// Sort and print result
		outLine = sort(stack);
		cout << outLine << endl;*/

		// Clean out containers for next iteration
		stack.clear();
		converter.clear();

		// Read next stack of pancakes
		getline(cin, inLine);
		converter.str(inLine);
		while(!converter.eof()) {
			converter >> inSize;
			stack.push_back(inSize);
		}
	}
}

string sort(list<int> stack) {
	int max_IndexFromBottom = stack.size();
	int curr_IndexFromBottom = stack.size();
	list<int>::iterator max = stack.begin();
	list<int>::iterator currBottom = --stack.end();
	list<int>::iterator curr = stack.begin();
	string retString = "";

	// Find maximum
	while(curr != currBottom) {
		if(*curr > *max) {
			max = curr;
			max_IndexFromBottom = curr_IndexFromBottom;
		}
		curr_IndexFromBottom--;
		curr++;
	}

	// Flip max to top
	if(max_IndexFromBottom == 0;
	flip(stack, max_IndexFromBottom);




