
#include <iostream>

#include "logger.h"
using namespace std;

void __logLevel(int level, string tag, string method, string msg){

	string le;
    switch(level){
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

    cout << "LOG("+ le +"), TAG = " << tag + ", called [ " + method +"()]: " << msg << endl;
}

void logV(string tag, string method, string msg){
	__logLevel(LEVEL_VERBOSE, tag , method, msg);
}
void logD(string tag, string method, string msg){
	__logLevel(LEVEL_DEBUG, tag , method, msg);
}
void logI(string tag, string method, string msg){
	__logLevel(LEVEL_INFO, tag , method, msg);
}
void logW(string tag, string method, string msg){
	__logLevel(LEVEL_WARN, tag , method, msg);
}
void logE(string tag, string method, string msg){
	__logLevel(LEVEL_ERROR, tag , method, msg);
}
void logA(string tag, string method, string msg){
	__logLevel(LEVEL_ASSERT, tag , method, msg);
}
void log(string msg){
	 cout << msg << endl;
}
