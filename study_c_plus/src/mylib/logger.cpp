#include <iostream>
#include <stdarg.h> //可变参数

#include "logger.h"
using namespace std;

void __logImpl(short int level, string tag, string method, bool newline, int count, ...);

string level2String(short int level){
	string le;
		switch (level) {
		case LEVEL_VERBOSE:
			le = "VERBOSE";
			break;
		case LEVEL_DEBUG:
			le = "DEBUG";
			break;

		default:
		case LEVEL_INFO:
			le = "INFO";
			break;

		case LEVEL_WARN:
			le = "WARN";
			break;
		case LEVEL_ERROR:
			le = "ERROR";
			break;
		case LEVEL_ASSERT:
			le = "ASSERT";
			break;
		}
	return le;
}

void __logLevel(short int level, string tag, string method, string msg) {
	__logImpl(level, tag, method, true, 1, msg);
   /*
	cout << "LOG(" + level2String(level) + "), TAG = " << tag + ", called [ " + method + "()]: "
			<< msg << endl;*/
}

void logV(string tag, string method, string msg) {
	__logLevel(LEVEL_VERBOSE, tag, method, msg);
}
void logD(string tag, string method, string msg) {
	__logLevel(LEVEL_DEBUG, tag, method, msg);
}
void logI(string tag, string method, string msg) {
	__logLevel(LEVEL_INFO, tag, method, msg);
}
void logW(string tag, string method, string msg) {
	__logLevel(LEVEL_WARN, tag, method, msg);
}
void logE(string tag, string method, string msg) {
	__logLevel(LEVEL_ERROR, tag, method, msg);
}
void logA(string tag, string method, string msg) {
	__logLevel(LEVEL_ASSERT, tag, method, msg);
}
void logM(string msg) {
	logM(msg, true);
}
void logM(string msg, bool newline) {
	if (newline) {
		cout << msg << endl;
	} else {
		cout << msg;
	}
}
void logM2(string m1, string m2) {
	cout << m1 << m2 << endl;
}

void logD2(string tag, string method, string m1, string m2){
	__logImpl(LEVEL_DEBUG, tag, method, true, 2, m1, m2);
}
void logI2(string tag, string method, string m1, string m2){
	__logImpl(LEVEL_INFO, tag, method, true, 2, m1, m2);
}
void logW2(string tag, string method, string m1, string m2){
	__logImpl(LEVEL_WARN, tag, method, true, 2, m1, m2);
}
void logE2(string tag, string method, string m1, string m2){
	__logImpl(LEVEL_ERROR, tag, method, true, 2, m1, m2);
}

void __logImpl(short int level, string tag, string method, bool newline, int count, ...) {
	cout << "LOG(" + level2String(level)  + "), TAG = " << tag + ", called [ " + method + "()]: ";

	va_list valist;
	//初始化指定个数的valist
    va_start(valist, count);
    for(int i=0 ; i< count ;i ++){
    	cout << va_arg(valist, void*);
    }
    //清理valist的内存
    va_end(valist);

    if(newline){
    	cout << endl;
    }
}

