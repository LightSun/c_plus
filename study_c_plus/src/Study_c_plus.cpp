//============================================================================
// Name        : Study_c_plus.cpp
// Author      : heaven7
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "base/string1.h"
using namespace std;
using namespace potter;

//取别名
typedef string1 str1;
//枚举
enum color {
	red, green, blue
} c = green;

int testDataTypeSize();
void testMutable();
void testCharArray();
void testString();
void testRefer();

int main() {
	cout << "!!!Hello World!!! please input string..." << endl; // prints !!!Hello World!!!
	string str;
	cin >> str;
	//self namespace
	str1 s(2);
	cout << "string1 id = " << s.getId() << " ,extra = " << str << endl;
	cout << c << endl;

	testDataTypeSize();
	testMutable();
	testCharArray();
	testString();
	testRefer();
	return 0;
}


