
#include "../../mylib/logger.h"
using namespace heaven7;

class TestB {
public:

	TestB(int val){
		this->m_iNum = val;
	}

	int m_iNum;

};

void test_ConstCast() {

	/**
	 * 常量 方面 c++ 和java不同。
	 * java 即使定义 一个final类型的对象。它的成员函数是可以被修改的。
	 * c++必须const_cast转换后才可以.(const_cast用于 去除const,volatile等属性)
	 */
	const TestB* b1 = new TestB(5);

	//b1->m_iNum = 100; //comile error

	TestB* b2 = const_cast<TestB*>(b1);

	b2->m_iNum = 200; //fine
	logT2("after const_cast: b2->m_iNum = ", b2->m_iNum);
	delete b1;

	Logger* hlg = new Logger();
	hlg->tag("TestTag")
			->level(LEVEL_INFO)
			->method("test_ConstCast")
	        ->lt3(2, "1111", "2222");
	delete hlg;
}
