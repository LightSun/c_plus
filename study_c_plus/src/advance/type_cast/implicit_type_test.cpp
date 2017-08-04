

# include "type_cast.h"
# include "../../mylib/logger.h"

extern double test_Sqrt(double);

//测试隐式类型转化
void testImplicit_type_conversion(){
	//1) 算术转换
	int ival = 3;
	double dval = 3.14159;

	int value = ival + dval;//ival被提升为double类型


    //2 一种类型表达式赋值给另一种类型的对象：目标类型是被赋值对象的类型
	int *pi = 0; // 0被转化为int *类型
	ival = dval; // double->int

	//3 , 参数传递，类型自动转化
	cout << "The square root of 2 is " << test_Sqrt(2) << endl;
}


//4, 返回值类型自动转化
double difference(int ival1, int ival2){
    return ival1 - ival2;
    //返回值被提升为double类型
}
