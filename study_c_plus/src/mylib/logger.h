#include <string>
#include <sstream>
#include <iostream>
#include <stdarg.h>
using namespace std;

const short int LEVEL_VERBOSE = 2;
const short int LEVEL_DEBUG = 3;
const short int LEVEL_INFO = 4;
const short int LEVEL_WARN = 5;
const short int LEVEL_ERROR = 6;
const short int LEVEL_ASSERT = 7;
//#define LEVEL_INFO 4; can't use for switch

string level2String(short int level);

template<typename T>
inline string object2String(T t) {
	ostringstream s;
	s << t;
	return s.str();
}

template<class T>
inline int getArrayLen(T& array) {
	return (sizeof(array) / sizeof(array[0]));
}

template<typename T1, typename T2>
inline void logT2(T1 t1, T2 t2) {
	cout << t1 << t2 << endl;
}
template<typename T1, typename T2, typename T3>
inline void logT3(T1 t1, T2 t2, T3 t3) {
	cout << t1 << t2 << t3 << endl;
}

void logV(string tag, string method, string msg);
void logD(string tag, string method, string msg);
void logI(string tag, string method, string msg);
void logW(string tag, string method, string msg);
void logE(string tag, string method, string msg);
void logA(string tag, string method, string msg);

void logM(string msg);
void logM(string msg, bool newline);

void logM2(string m1, string m2);
void logD2(string tag, string method, string m1, string m2);
void logI2(string tag, string method, string m1, string m2);
void logW2(string tag, string method, string m1, string m2);
void logE2(string tag, string method, string m1, string m2);

#ifndef __com_heaven7_com_loglib__
#define __com_heaven7_com_loglib__

namespace heaven7 {
class Logger {
public:
	Logger() {
		_level = LEVEL_DEBUG;
		_level_str = level2String(_level);
		_tag = "";
		_method = "";
		_newline = true;
	}

	template<typename T1, typename T2, typename T3>
	inline Logger* lt3(T1 t1, T2 t2, T3 t3) {
		cout << "LOG(" + _level_str + "), TAG = "
				<< _tag + ", called [ " + _method + "()]: " << t1 << t2 << t3;
		if (_newline) {
			cout << endl;
		}
		return this;
	}
	template<typename T1, typename T2>
	inline Logger* lt2(T1 t1, T2 t2) {
		cout << "LOG(" + _level_str + "), TAG = "
				<< _tag + ", called [ " + _method + "()]: " << t1 << t2;
		if (_newline) {
			cout << endl;
		}
		return this;
	}

	template<typename T1>
	inline Logger* lt(T1 t) {
		cout << "LOG(" + _level_str + "), TAG = "
				<< _tag + ", called [ " + _method + "()]: " << t;
		if (_newline) {
			cout << endl;
		}
		return this;
	}

	Logger* level(short int level) {
		this->_level = level;
		_level_str = level2String(_level);
		return this;
	}
	Logger* tag(string tag) {
		this->_tag = tag;
		return this;
	}
	Logger* method(string method) {
		this->_method = method;
		return this;
	}
	Logger* newline(bool newline) {
		this->_newline = newline;
		return this;
	}

private:
	short int _level; //直接初始化。std11++才支持
	string _level_str;
	string _tag;
	string _method;
	bool _newline;
};
}
#endif /* __com_heaven7_com_loglib__ */

