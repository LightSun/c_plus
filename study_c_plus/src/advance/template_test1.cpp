/**
 * 模版的一般形式：
 template <class type> ret-type func-name(parameter list)
 {
 // 函数的主体
 }
 */
#include <iostream>
#include <string>
#include "../mylib/logger.h"

using namespace std;

//模版： 返回2个数种的最大值 .
//typename 换成 class 一样可以
template<typename T>
inline T const& maxValue(T const& a, T const& b) { //代码比较少。用inline减少call开销
	return a < b ? b : a;
}

/**
 * 简单模版使用
 */
void testTemplate1() {
	logM("======== start testTemplate1() ===========");

	int i = 39;
	int j = 20;
	logT2("Max(i, j): ", max(i, j));

	double f1 = 13.5;
	double f2 = 20.7;
	logT2("Max(f1, f2): ", maxValue(f1, f2));

	string s1 = "Hello";
	string s2 = "World";
	logT2("Max(s1, s2): " , maxValue(s1, s2));
}
