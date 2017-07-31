/**
 * #pragma once用来防止某个头文件被多次include，#ifndef，#define，#endif用来防止某个宏被多次定义。
　　#pragma once是编译相关，就是说这个编译系统上能用，但在其他编译系统不一定可以，也就是说移植性差，不过现在基本上已经是每个编译器都有这个定义了。
 */
#pragma once  //头文件只被编译一次
#include "MyNameSpace.h"
using namespace potter;

//第二种加入自定义命名空间的自定义类
class string1 {
public:
	string1(int);
	~string1(void);
	int getId();
private:
	int id;
};
