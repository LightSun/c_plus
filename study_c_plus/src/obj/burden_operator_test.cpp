/**
 * c++ 运算操作符的重载。
 *  Note:  运算符重载不改变运算符的优先级与结合性，如/的优先级比-高;
 *         运算符重载不改变部分运算符对操作数个数的限制，如+只能有两个操作数;
 *  可以重载的:
 *        new  delete  new[]  delete[]
 *        +     -     *    /     %
 *        ++    --
 *        !     ^     &    |     ~
 *        &&    ||
 *
 *        <     >     !=   <=    >=
 *        =     +=    -=   *=    /=   %=  ^=   &=   |=
 *        <<    >>    >>=  <<=   ==
 *
 *        ->*   ->     ()  []
 *        ，
 *
 *  不可重载的：
 *       .     .*    ::     ?:
 * 其中，“::”是作用域运算符，
		“?:”是条件运算符。

		两个较少使用的运算符是 .* 和 ->* 分别是：
		.* 对象调用成员函数指针；
		->* 对象指针调用成员函数指针；
 *
 *
 */

#include <iostream>
#include "../mylib/logger.h"
using namespace std;

class BoxBurdenOperator {
public:

	double getVolume(void) {
		return length * breadth * height;
	}
	void setLength(double len) {
		length = len;
	}

	void setBreadth(double bre) {
		breadth = bre;
	}

	void setHeight(double hei) {
		height = hei;
	}
	// 重载 '+' 运算符，用于把两个 Box 对象相加
	BoxBurdenOperator operator+(/*const*/ BoxBurdenOperator& b) {
		BoxBurdenOperator box;
		box.length = this->length + b.length;
		box.breadth = this->breadth + b.breadth;
		box.height = this->height + b.height;
		return box;
	}
private:
	double length;      // 长度
	double breadth;     // 宽度
	double height;      // 高度
};
// 程序的主函数
void testBurdenOperator() {
	logM("======= start testBurdenOperator() ========");
	BoxBurdenOperator Box1;                // 声明 Box1，类型为 Box
	BoxBurdenOperator Box2;                // 声明 Box2，类型为 Box
	BoxBurdenOperator Box3;                // 声明 Box3，类型为 Box
	double volume = 0.0;     // 把体积存储在该变量中

	// Box1 详述
	Box1.setLength(6.0);
	Box1.setBreadth(7.0);
	Box1.setHeight(5.0);

	// Box2 详述
	Box2.setLength(12.0);
	Box2.setBreadth(13.0);
	Box2.setHeight(10.0);

	// Box1 的体积
	volume = Box1.getVolume();
	cout << "Volume of Box1 : " << volume << endl;

	// Box2 的体积
	volume = Box2.getVolume();
	cout << "Volume of Box2 : " << volume << endl;

	// 把两个对象相加，得到 Box3
	Box3 = Box1 + Box2;

	// Box3 的体积
	volume = Box3.getVolume();
	cout << "Volume of Box3 : " << volume << endl;
}
