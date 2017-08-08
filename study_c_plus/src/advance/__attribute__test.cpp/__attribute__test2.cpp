/**
 * __attribute__ format  该属性可以给被声明的函数加上类似printf或者scanf的特征，
 * 它可以使编译器检查函数声明和函数实际调用参数之间的格式化字符串是否匹配。该功能十分有用，尤其是处理一些很难发现的bug。

format的语法格式为：format (archetype, string-index, first-to-check)

format属性告诉编译器，按照 printf, scanf, strftime或strfmon的参数表格式规则对该函数的参数进行检查。
“archetype”指定是哪种风格；“string-index”指定传 入函数的第几个参数是格式化字符串；
“first-to-check”指定从函数的第几个参数开始按上述规则进行检查。
 */

#include <stdio.h>
#include <string>
#include "../../mylib/logger.h"
using namespace std;

// m = 1, n = 2...如果在这里myprint()为类成员函数,则gcc编译后会提示"format argument is not a pointer"的警告
/**
 * 这句主要作用是[提示编译器]，对这个函数的调用需要像printf一样，用对应的format字符串来check可变参数的数据类型
 * 1： 这里表示第 1 个参数为格式化字符串
 * 2: 第  2 个参数开始按上述规则进行检查.
 */
extern void myprint(const char *format, ... ) __attribute__((format(printf,1,2)));

extern void myprint(short num, const char *format,...) __attribute__((format(printf,2,3)));

class TestAttribute{
public:
	//void myprint(const char *format, ... ) __attribute__((format(printf,1,2))); //error
	//in class first argument is 'this'
	void myprint(const char *format, ... ) __attribute__((format(printf,2,3)));
};


/**
 * __attribute__ format
 */
void testAttributeFormat(){
	logM("============= start testAttributeFormat() =================");
    const char* str = "i am %c, %d years old";
    const char* name = "heaven7";
    int age = 22;
    myprint(str, name, age);
}

//实现
void myprint(const char *format, ...){
      //your impl
}
