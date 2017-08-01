
class VirtualTest {
protected:
	int width, height;
public:
	VirtualTest(int a = 0, int b = 0) {
		width = a;
		height = b;
	}

	//有虚构函数就应该有 虚析构函数. 否则警告
	virtual ~VirtualTest() {};

	// pure virtual function 纯虚函数. 类似java的抽象方法
	virtual int area() = 0;
};

class VirtualTest2 :public  VirtualTest{

	int area(){
		return 1;
	}
};
