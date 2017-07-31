#include <iostream>
using namespace std;

/**
85         // 十进制
0213       // 八进制
0x4b       // 十六进制
30         // 整数
30u        // 无符号整数
30l        // 长整数
30ul       // 无符号长整数
 */


int testDataTypeSize()
{
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl; //4 in my 64-bit system
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
   return 0;
}
