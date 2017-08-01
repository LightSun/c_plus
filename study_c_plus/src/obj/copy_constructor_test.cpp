/**
 * 拷贝构造函数的使用.
 *
X::X(const X&);  //是拷贝构造函数
X::X(X&, int=1); //是拷贝构造函数
X::X(X&, int a=1, int b=2); //是拷贝构造函数
 */
/**
 * 以下情况都会调用拷贝构造函数：
 *      （1）一个对象以值传递的方式传入函数体
		（2）一个对象以值传递的方式从函数返回
		（3）一个对象需要通过另外一个对象进行初始化。
 */
#include <iostream>
using namespace std;

class Line {
public:
	int getLength(void);
	Line(int len);               // 简单的构造函数
	Line(const Line &obj);       // 拷贝构造函数, 成员变量有动态对象成员(比如指针)，请加上.
	~Line();                     // 析构函数. 相当于java的finalize

private:
	int *ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len) {
	cout << "调用构造函数" << endl;
	// 为指针分配内存
	ptr = new int;
	*ptr = len;
}

//用于深拷贝
Line::Line(const Line &obj) {
	cout << "调用--拷贝构造函数--并为指针 ptr 分配内存" << endl;
	ptr = new int;
	*ptr = *obj.ptr; // 拷贝值. 否则复制对象后会调用多次 delete ptr（析构）.造成同一内存释放多次
}

Line::~Line(void) {
	cout << "释放内存" << endl;
	delete ptr;
}
int Line::getLength(void) {
	return *ptr;
}

void display(Line obj) {
	cout << "line 大小 : " << obj.getLength() << endl;
}

// 拷贝构造函数
void testCopyConstructor() {
	Line line1(10); //call 拷贝构造函数

	display(line1);

	//Line line2 = line1; // 这里也调用了拷贝构造函数
	//display(line2);
}
