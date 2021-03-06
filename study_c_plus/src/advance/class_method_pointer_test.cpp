
#include <iostream>
using namespace std;

class CA;

//指向类的非静态成员函数的指针，在声明时就需要添加类名。
/*指向类的非静态成员函数的指针*/
typedef int (CA::*pClassFun)(int, int);

/*指向一般函数的指针 ( 格式:  返回值类型     函数指针别名  （参数类型...）  )*/
typedef int (*pGeneralFun)(int, int);

class CA {
public:

	int Max(int a, int b) {
		return a > b ? a : b;
	}

	int Min(int a, int b) {
		return a < b ? a : b;
	}

	static int Sum(int a, int b) {
		return a + b;
	}

	/*类内部的接口函数，实现对类的非静态成员函数的封装*/
	int Result(pClassFun fun, int a, int b) {
		return (this->*fun)(a, b);
	}

};

/*类外部的接口函数，实现对类的非静态成员函数的封装.
 * */
//对象指针调用成员函数
int Result(CA* pA, pClassFun fun, int a, int b) {
	return (pA->*fun)(a, b);
}

//对象调用成员函数指针
int Result2(CA pA, pClassFun fun, int a, int b) {
	return (pA.*fun)(a, b);
}

/*类外部的接口函数，实现对类的静态成员函数的封装(同一般的函数指针)*/
int GeneralResult(pGeneralFun fun, int a, int b) {
	return (*fun)(a, b);
}

/**
 * 测试c++. 成员函数指针 和 类的static函数指针
 */
void testClassMethodPointer() {
	CA ca;
	int a = 3;
	int b = 4;

	// c++ .类的函数指针。必须用&. 这个不同于c的指针
	cout << "Test nonstatic member function pointer from member function:"
			<< endl;
	cout << "The maximum number between a and b is " << ca.Result(&CA::Max, a, b)
			<< endl;
	cout << "The minimum number between a and b is " << ca.Result(&CA::Min, a, b)
			<< endl;

	cout << endl;
	cout << "Test nonstatic member function pointer from external function:"
			<< endl;
	cout << "The maximum number between a and b is "
			<< Result(&ca, &CA::Max, a, b) << endl;
	cout << "The minimum number between a and b is "
			<< Result(&ca, &CA::Min, a, b) << endl;

	cout << "The minimum number between a and b is "
				<< Result2(ca, &CA::Min, a, b) << endl;

	cout << endl;
	cout << "Test static member function pointer: " << endl;
	cout << "The sum of a and b is " << GeneralResult(CA::Sum, a, b) << endl;
}
