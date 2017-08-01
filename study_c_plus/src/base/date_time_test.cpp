/**
 * time.h
 * struct tm {
 int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
 int tm_min;   // 分，范围从 0 到 59
 int tm_hour;  // 小时，范围从 0 到 23
 int tm_mday;  // 一月中的第几天，范围从 1 到 31
 int tm_mon;   // 月，范围从 0 到 11
 int tm_year;  // 自 1900 年起的年数
 int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
 int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
 int tm_isdst; // 夏令时
 }
 */

#include <ctime>
#include <iostream>
#include "../mylib/logger.h"
using namespace std;

void testDateTime() {

	const string tag = "NONE";
	const string method = "testDateTime";
	//current time
	time_t now = time(0);
	//convert to string(char*)
	char* dt = ctime(&now);

logD(tag, method, "local date and time: " + (string) dt);
	cout << "local date and time: " << dt << endl; //local date and time: Tue Aug 01 10:17:13 2017
	//convert to gm time (utc)
	tm* gmtm = gmtime(&now);

	//convert gm time to string
	dt = asctime(gmtm);
	cout << "UTC date and time: " << dt << endl; //UTC date and time: Tue Aug 01 02:17:13 2017

	tm* ltm = localtime(&now);
	// 输出 tm 结构的各个组成部分
	cout << "Year: " << 1900 + ltm->tm_year << endl;
	cout << "Month: " << 1 + ltm->tm_mon << endl;
	cout << "Day: " << ltm->tm_mday << endl;
	cout << "Time: " << ltm->tm_hour << ":";
	cout << 1 + ltm->tm_min << ":";
	cout << 1 + ltm->tm_sec << endl;
}
