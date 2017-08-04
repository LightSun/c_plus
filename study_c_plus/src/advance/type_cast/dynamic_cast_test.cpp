# include "Emplyes.h"

//自定义类
class Programmer: public Employee {
public:
	int salary();
	int bonus(); //直接在这里扩展
};


int Programmer::bonus() {
	//define
	return 0;
}

//自定义类
class MyCompany {
public:
	void payroll(Employee *pe);
	//
};

//MyCompany 实现
void MyCompany::payroll(Employee *pe) {
	/**
	 * dynamic_cast主要用于类层次间的上行转换和下行转换，还可以用于类之间的交叉转换。
在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；在进行下行转换时，
dynamic_cast具有类型检查的功能，比static_cast更安全。
	 */
	Programmer* pm = dynamic_cast<Programmer*>(pe);
    pm->bonus();
    //do anything we want.
}
