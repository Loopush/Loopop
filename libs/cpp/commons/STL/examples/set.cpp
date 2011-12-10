// Program: Set Demo
// Purpose: To demonstrate STL sets

// #include "stdafx.h" - include if you use pre compiled headers
#include <string>
#include <set>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	set <string> strset;
	set <string>::iterator si;
	strset.insert("cantaloupes");
	strset.insert("apple");
	strset.insert("orange");
	strset.insert("banana");
	strset.insert("grapes");
	strset.insert("grapes");	// This one overwrites the previous occurrence
	for (si=strset.begin(); si!=strset.end(); si++)	
	{	cout << *si << " ";	}
	cout << endl;
	return 0;
}

// Output: apple banana cantaloupes grapes orange
