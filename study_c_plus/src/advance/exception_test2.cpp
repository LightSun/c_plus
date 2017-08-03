#include <iostream>
#include <exception>
#include "../mylib/logger.h"
using namespace std;

//自定义异常
class MyException: public exception {

public:
	//重写的虚函数，必须public
	/**
	 * const throw() 不是函数，这个东西叫异常规格说明，表示 what函数可以抛出异常的类型，类型说明放到 () 里，
	 * 这里面没有类型，就表示函数可以抛出任何类型的异常。
	 * eg: void fun() throw(A，B，C，D);
	 */
	const char * what() const throw () {
		return "MyException____C++ Exception";
	}
};

class MyExceptionD {

public:
	//构造函数加   ':message_(message) ' 感觉像自动赋值给成员的意思. 效果等同于setMessage(message)
	MyExceptionD(const char *message)
           /* :message_(message) */  {
		setMessage(message);
		cout << "normal MyExceptionD ..." << endl;
	}
	MyExceptionD(const MyExceptionD &other) : // 拷贝构造函数
			message_(other.message_) {
		cout << "(拷贝构造函数)MyExceptionD ..." << endl;
	}
	virtual ~MyExceptionD() { //虚析构函数
		cout << "~MyExceptionD ..." << endl;
	}
	const char *what() const {
		return message_.c_str();
	}

private:
	string message_;
	void setMessage(const char *message){
        message_ = string(message);
	}
};

void fun(int n) throw/*()*/(int, MyException, MyExceptionD) {
	if (n == 1) {
		throw 1;
	} else if (n == 2) {
		throw MyException();
	} else if (n == 3) {
		throw MyExceptionD("test ExceptionD");
	}

}

/**
 * 测试自定义异常
 */
void testException2() {
	logM("===== start testException2() ============");
	try {
		throw MyException();
	} catch (MyException& e) {
		std::cout << "MyException caught" << std::endl;
		std::cout << e.what() << std::endl;
	} catch (std::exception& e) {
		//其他的错误
	}

	try {
		fun(3);
	} catch (int e) {
		logM("exception ----int " + e);
	} catch (MyException& e) {
		logM("exception ----MyException ", false);
		logM(e.what());
	} catch (MyExceptionD& e) {
		logM("exception ----MyExceptionD ", false);
		logM(e.what());
	}
}



