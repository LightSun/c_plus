/**
 try{
 // 保护代码
 }catch( ExceptionName e1 ){
 // catch 块
 }catch( ExceptionName e2 )
 {
 // catch 块
 }catch( ExceptionName eN )
 {
 // catch 块
 }

 try
 {
 // 保护代码
 }catch(...)
 {
 // 能处理任何异常的代码
 }
 */
#include <iostream>
#include <string>
#include "../mylib/logger.h"
using namespace std;

double division(int a, int b) {
	if (b == 0) {
		throw "Division by zero condition!"; //抛出 const char*
	}
	return (a / b);
}

void testException() {
	logM("=========== start testException()=============");
	int x = 50;
	int y = 0;
	double z = 0;

	try {
		z = division(x, y);
		cout << z << endl;
	}/*catch(string msg){  //这里用string无用.
		cerr << "as string " << msg << endl;
	} */catch (const char* msg) {
		cerr << msg << endl;
		/** 如果这里捕获不加const.则会报
 This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.
terminate called after throwing an instance of 'char const*'
		 */
	}
}
