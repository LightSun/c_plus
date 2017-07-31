#include <iostream>
#include <iomanip>
using namespace std;

void testArray() {
	double balance[10]; //声明
	double balance2[5] = { 1000.0, 2.0, 3.4, 17.0, 50.0 }; //声明+赋值
}

void testCharArray() {
	char a1[] = { 'C', '+', '+' };          // 初始化，没有 null
	char a2[] = { 'C', '+', '+', '\0' };    // 初始化，明确有 null
	char a3[] = "C++";                    // null 终止符自动添加
	//const char a4[6] = "runoob";          // 报错，没有 null 的位置
	const char a4[8] = "runoob\0";
	cout << a4[5] << a4[6] << a4[7] << sizeof(a4) << endl;

	/**
	 * 在C++中，setw(int n)用来控制输出间隔,（n-1个空格）。
              setw()默认填充的内容为空格，可以setfill()配合使用设置其他字符填充。
	 */
	cout << setfill('*') << setw(5) << 'a' << endl;
}
