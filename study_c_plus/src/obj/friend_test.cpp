#include <iostream>

using namespace std;

/**
 * 类的友元函数是定义在类外部，可访问类的（private）成员和protected）成员。
 * 尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，在这种情况下，
整个类及其所有成员都是友元。如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 friend，

友元函数没有 this 指针，因为友元不是类的成员。只有成员函数才有 this 指针。
 */
class Box {
	    double width; //默认private
	public:
	    //友元函数，非成员函数
		friend void printWidth(Box box); //friend 关键字
		void setWidth(double wid);
};

// 成员函数定义
void Box::setWidth(double wid) {
	width = wid;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box) {
	/* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
	cout << "Width of box : " << box.width << endl;
}

//友元函数
void testFriend() {
	Box box;

	// 使用成员函数设置宽度
	box.setWidth(10.0);

	// 使用友元函数输出宽度
	printWidth(box);

}
