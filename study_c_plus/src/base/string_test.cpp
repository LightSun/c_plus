#include <iostream>
#include <cstring> //或者string.h
#include <string>  //c++中的string

using namespace std;

void testString2();

void testString() {
	char greeting[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	cout << "Greeting message: ";
	cout << greeting << endl;

	char str1[11] = "Hello";
	char str2[11] = "World";
	char str3[11];
	int len;

	// 复制 str1 到 str3
	strcpy(str3, str1);
	cout << "strcpy( str3, str1) : " << str3 << endl;

	// 连接 str1 和 str2
	strcat(str1, str2);
	cout << "strcat( str1, str2): " << str1 << endl;

	// 连接后，str1 的总长度
	len = strlen(str1);
	cout << "strlen(str1) : " << len << endl;
	testString2();
}

//和java相同
void testString2() {
	cout << "start >>> testString2()......"<< endl;
	string str1 = "Hello";
	string str2 = "World";
	string str3;
	int len;

	// 复制 str1 到 str3
	str3 = str1;
	cout << "str3 : " << str3 << endl;

	// 连接 str1 和 str2
	str3 = str1 + str2;
	cout << "str1 + str2 : " << str3 << endl;

	// 连接后，str3 的总长度
	len = str3.size();
	cout << "str3.size() :  " << len << endl;
}
