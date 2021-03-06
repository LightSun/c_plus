#include <iostream>

using namespace std;

class BoxStatic {
public:
	static int objectCount;
	// 构造函数定义
	BoxStatic(double l = 2.0, double b = 2.0, double h = 2.0) {
		cout << "Constructor called." << endl;
		length = l;
		breadth = b;
		height = h;
		// 每次创建对象时增加 1
		objectCount += 1;
	}
	double Volume() {
		return length * breadth * height;
	}
private:
	double length;     // 长度
	double breadth;    // 宽度
	double height;     // 高度
};

// 初始化类 Box 的静态成员   其实是定义并初始化的过程
int BoxStatic::objectCount = 0;
//也可这样 定义却不初始化
//int Box::objectCount;

void testStatic(void) {
	BoxStatic Box1(3.3, 1.2, 1.5);    // 声明 box1
	BoxStatic Box2(8.5, 6.0, 2.0);    // 声明 box2

	// 输出对象的总数
	cout << "Total objects: " << BoxStatic::objectCount << endl;
}
