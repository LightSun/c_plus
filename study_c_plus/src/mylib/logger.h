
#include <string>
using namespace std;

const short int LEVEL_VERBOSE = 2;
const short int LEVEL_DEBUG   = 3;
const short int LEVEL_INFO    = 4;
const short int LEVEL_WARN    = 5;
const short int LEVEL_ERROR   = 6;
const short int LEVEL_ASSERT  = 7;
//#define LEVEL_INFO 4; can't use for switch


void logV(string tag, string method, string msg);
void logD(string tag, string method, string msg);
void logI(string tag, string method, string msg);
void logW(string tag, string method, string msg);
void logE(string tag, string method, string msg);
void logA(string tag, string method, string msg);

void log(string msg);
