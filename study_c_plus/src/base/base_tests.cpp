

#include <iostream>
#include <string>
#include "string1.h"
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
void testDateTime();
void testStdIO();
void testStruct();
;
/**
 * test all base demo.
 */
void testAllBase(){
	testStdIO();
    testDataTypeSize();
	testMutable();
	testCharArray();
	testString();
	testRefer();
	testDateTime();
	testStruct();
}
void testStdIO(){
	cout << "!!!Hello World!!! please input string..." << endl; // prints !!!Hello World!!!
	string str;
	cin >> str; //input
	//self namespace
	str1 s(2);
	cout << "string1 id = " << s.getId() << " ,extra = " << str << endl;
	cout << c << endl;
	cerr << "test Error message : " << endl;
	clog << "test log message : " << endl;
}
