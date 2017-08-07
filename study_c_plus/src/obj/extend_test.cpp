#include <iostream>

using namespace std;

// 基类 (c++没有私有的class)
class Shape {
public:
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}
	int getCost(int area) {
			return area * 10;
	}
protected:
	int width;
	int height;
};

// 基类 PaintCost
class PaintCost {
public:
	int getCost(int area) {
		return area * 70;
	}
};

// 子类 (可以访问父类非private成员 ) 这里继承2个类
class Rectangle: public Shape, public PaintCost {
public:
	int getArea() {
		return (width * height);
	}

	int getCost(int area) {
		//c++ 支持多继承。 如果所以最好在前面加上类名前缀。 免得出错。
		return PaintCost::getCost(area);
	}
};

/**
 * c++和java关于继承的区别: 就是c++允许多继承(可能会导致一些问题)
 * 多态同java
 */
void testExtends(void) {
	Rectangle rect;

	rect.setWidth(5);
	rect.setHeight(7);

	// 输出对象的面积
	cout << "Total area: " << rect.getArea() << endl;
	// 输出总花费
	cout << "Total paint cost: $" << rect.getCost(rect.getArea()) << endl;
}
