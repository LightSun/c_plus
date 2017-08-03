/**
 * 动态内存: new & delete, (new的对象在堆内存)
 * c语言中的malloc最好不用, new 既分配了内存还创建了对象。
 */

#include <iostream>
#include "../mylib/logger.h"
using namespace std;

class DynamicMemory{
public :
	DynamicMemory(){
		cout << "调用构造函数！" <<endl;
	}
	~DynamicMemory(){
		cout << "调用析构函数！" <<endl;
	}
};

void testDoubleArray();

/**
 * 测试动态内存
 */
void testDynamicMemory() {
logM("====== start testDynamicMemory()==================");
	double* pvalue = NULL; // 初始化为 null 的指针
	pvalue = new double;   // 为变量请求内存

	*pvalue = 29494.99;     // 在分配的地址存储值
	cout << "Value of pvalue : " << *pvalue << endl;

	delete pvalue;         // 释放内存

	//动态分配数组
	int * arr = new int[6];
	arr[0] = 1;

	delete[] arr; //释放数组内存

	testDoubleArray();

	//test dynamic object(动态对象)
	DynamicMemory *dm = new DynamicMemory[4];
	delete []dm;
}

//2维数组
void testDoubleArray() {
	int **p;
	int i, j;   //p[4][8]
	//开始分配4行8列的二维数据
	p = new int *[4];
	for (i = 0; i < 4; i++) {
		p[i] = new int[8];
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			p[i][j] = j * i;
		}
	}
	//打印数据
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			if (j == 0)
				cout << endl;
			cout << p[i][j] << "\t";
		}
	}
	cout << endl;
	//开始释放申请的堆
	for (i = 0; i < 4; i++) {
		delete[] p[i];
	}
	delete[] p;
}

