
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

const short int LEVEL_VERBOSE = 2;
const short int LEVEL_DEBUG   = 3;
const short int LEVEL_INFO    = 4;
const short int LEVEL_WARN    = 5;
const short int LEVEL_ERROR   = 6;
const short int LEVEL_ASSERT  = 7;
//#define LEVEL_INFO 4; can't use for switch


template <typename T>
inline string object2String(T t){
    ostringstream s;
    s << t;
    return s.str();
}
template <typename T1, typename T2>
inline void logT2(T1 t1, T2 t2){
    cout << t1 << t2 << endl;
}
template <typename T1, typename T2, typename T3>
inline void logT3(T1 t1, T2 t2, T3 t3){
    cout << t1 << t2 << t3 << endl;
}

template <class T>
inline int getArrayLen(T& array){
    return (sizeof(array) / sizeof(array[0]));
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

