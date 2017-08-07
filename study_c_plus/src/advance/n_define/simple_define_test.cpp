#include <iostream>
using namespace std;

#define PI 3.14159265  //直接被替换

void testSimpleDefine() {

	cout << "Value of PI :" << PI << endl;
}

/*
//用命令编译：  gcc -E test.cpp > test.p
int main() {

	cout << "Value of PI :" << PI << endl;

	return 0;
}
*/

//__attribute__详解：  http://www.cnblogs.com/astwish/p/3460618.html
//c/c++ 预处理或者宏：    http://www.runoob.com/cplusplus/cpp-preprocessor.html
