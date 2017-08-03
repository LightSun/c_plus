
/**
 * 一般情况下。typename 和 class 在template 中作用是相同的
 * 记住： 不管什么时候，只要为指针声明 typedef，那么都要在最终的 typedef 名称中加一个 const，以使得该指针本身是常量，而不是对象。
 * ps: 备注了关于typedef 用法和陷阱
 */

class MyArray {
public:
	MyArray() {}
	~MyArray() {}
	typedef int size;
	/**
	此声明定义了一个 int 的同义字，名字为 size。注意 typedef 并不创建新的类型。它仅仅为现有类型添加一个同义字。你可以在任何需要 int 的上下文中使用 size：
	*/

};
/**
 * 下面这个嵌套代码:  typename 的作用就是告诉 c++ 编译器，typename 后面的字符串为一个类型名称，
 * 而不是成员函数或者成员变量，这个时候如果前面没有typename，
 * 编译器没有任何办法知道 T::LengthType 是一个类型还是一个成员名称(静态数据成员或者静态函数)，所以编译不能够通过。
 */
template<class T>
void MyMethod(T myarr) {
	typedef typename T::LengthType LengthType;
	LengthType length = myarr.GetLength;
}

/**
 * typedef 作用：
 * 1,  一般用于起别名(可在声明结构体时使用-- 类型，方法等)。
 * 2, 用typedef来定义与平台无关的类型。
		比如定义一个叫 REAL 的浮点类型，在目标平台一上，让它表示最高精度的类型为：
		typedef long double REAL;
		在不支持 long double 的平台二上，改为：
		typedef double REAL;
		在连 double 都不支持的平台三上，改为：
		typedef float REAL;
		也就是说，当跨平台时，只要改下 typedef 本身就行，不用对其他源码做任何修改。
		标准库就广泛使用了这个技巧，比如size_t。
		另外，因为typedef是定义了一种类型的新别名，不是简单的字符串替换，所以它比宏来得稳健（虽然用宏有时也可以完成以上的用途）。

	陷阱:
	1, typedef是定义了一种类型的新别名，不同于宏，它不是简单的字符串替换。比如：
		先定义：
		typedef char* PSTR;
		然后：
		int mystrcmp(const PSTR, const PSTR);
		const PSTR实际上相当于const char*吗？不是的，它实际上相当于char* const。
		原因在于const给予了整个指针本身以常量性，也就是形成了常量指针char* const。
		简单来说，记住当const和typedef一起出现时，typedef不会是简单的字符串替换就行。
    2, typedef在语法上是一个存储类的关键字（如auto、extern、mutable、static、register等一样），
                      虽然它并不真正影响对象的存储特性，如：
			typedef static int INT2; //不可行
			编译将失败，会提示“指定了一个以上的存储类”。
 *
 */
