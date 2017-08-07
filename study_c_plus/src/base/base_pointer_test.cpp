
#include <iostream>
#include "../mylib/logger.h"
using namespace std;

int m_value = 1;

/**
 * 修改的是拷贝的指针本身的值。 原指针不受影响。
 */
void func(int *p) {
	p = &m_value;
}

//传递的是指针的指针  **int
void func2(int **p) {
	*p = &m_value;

	// 也可以根据你的需求分配内存
	//*p = new int;
	**p = 5;
}

/**
 * 简单测试指针。
 */
void testSimplePointer1() {
	logM("====== start testSimplePointer1() ============");
	int n = 2;
	int *pn = &n;
	cout << "before func()" <<*pn << endl;
	func(pn);
	cout << "after func()" << *pn << endl;

	func2(&pn); // 传递的是指针的指针。所以可以修改指针和内容
	cout << "after func2()" << *pn <<endl;
	cout << "after func2(): m_value = " << m_value <<endl;
}
