/**
 典型案例：
 Wicrosoft公司提供给我们一个类库，其中提供一个类Employee.以头文件Eemployee.h和类库.lib分发给用户
 显然我们并无法得到类的实现的源代码.
 */
//合作方提供的
class Employee {
public:
	virtual int salary();
	virtual ~Employee() {
	}
};

class Manager: public Employee {
public:
	int salary();
};

