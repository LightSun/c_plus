#include <iostream>

using namespace std;

/**
 * 引用很容易与指针混淆，它们之间有三个主要的不同：
1, 不存在空引用,引用必须连接到一块合法的内存。
2, 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
3, 引用必须在创建时被初始化。指针可以在任何时间被初始化。
 */
void testRefer() {
	// 声明简单的变量
	int i;
	double d;

	// 声明引用变量( here 引用变量值r等同于 i)
	int& r = i;
	double& s = d;

	i = 5;
	cout << "Value of i : " << i << endl; //5
	cout << "Value of i reference : " << r << endl;

	d = 11.7;
	cout << "Value of d : " << d << endl; //5
	cout << "Value of d reference : " << s << endl;
}
