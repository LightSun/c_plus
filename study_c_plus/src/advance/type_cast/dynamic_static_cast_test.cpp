
class Base {
public:

	virtual ~Base() {

	}

	int m_iNum;
	virtual void foo() = 0; //纯虚函数
};

class Derived: public Base {
public:
	char *m_szName[100];

	void foo() {

	}
};

class Derived2: public Base {
	void foo() {

	}
};

/**
 * if pb is just a base class.
 * 那么pd1将是一个指向该对象的指针，对它进行Derived类型的操作将是不安全的（如访问m_szName），
 * 而pd2将是一个空指针(即0，因为dynamic_cast失败)。
 * 另外，注意。Base类要有虚函数， 否则会编译出错。 static_cast则没有这个限制。这是由于-运行时类型检查-需要运行时类的信息,
 * 而这个信息存储在类的虚函数表， 只有定义了虚函数的类才有虚函数表。没有定义虚函数的类没有虚函数表。
 */
void testCMP_Dynamic_static_cast(Base *pb) {

	Derived *pd1 = static_cast<Derived *>(pb);
	Derived *pd2 = dynamic_cast<Derived *>(pb);
	pd1->foo();
	pd2->foo();

	Derived *pd11 = new Derived;
	pd1->m_iNum = 100;

	//Derived2 *pd22 = static_cast<Derived2 *>(pd11); //compile error
	//Derived2 *pd22 = dynamic_cast<Derived2 *>(pd11); //error pd2 is NULL

	delete pd11;

}
