#include <iostream>
#include "../mylib/logger.h"
using namespace std;

/**
 * 一般的函数指针(C)
 */
/*指向函数的指针*/
typedef int (*pFun)(int, int);

int Max(int a, int b) {
	return a > b ? a : b;
}

int Min(int a, int b) {
	return a < b ? a : b;
}

/*通用接口函数，实现对其他函数的封装*/
int Result(pFun fun, int a, int b) {
	return (*fun)(a, b);
}

//函数指针
void testMethodPointer() {
    logM("=========== start testMethodPointer() ==============");
	int a = 3;
	int b = 4;

	cout << "Test function pointer: " << endl;
	cout << "The maximum number between a and b is " << Result(Max, a, b)
			<< endl;
	cout << "The minimum number between a and b is " << Result(Min, a, b)
			<< endl;
}
