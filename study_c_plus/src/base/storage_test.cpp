
/**
 * 存储说明:  http://www.runoob.com/cplusplus/cpp-storage-classes.html
 * extern :       存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。
 * mutable :      说明符仅适用于类的对象，这将在本教程的最后进行讲解。它允许对象的成员替代常量。也就是说，mutable 成员可以通过 const 成员函数修改。
 * thread_local:  使用 thread_local 说明符声明的变量仅可在它在其上创建的线程上访问。 变量在创建线程时创建，并在销毁线程时销毁。
 *                每个线程都有其自己的变量副本。thread_local 说明符可以与 static 或 extern 合并。
 * ps: 从 C++ 11 开始，auto 关键字不再是 C++ 存储类说明符，且 register 关键字被弃用。
 */

struct ST{
	int a;
	mutable int b;
};

void testMutable() {
	const ST st = { 1, 2 };
	//st.a = 11; //编译错误 read-only
	st.b = 22;  //ok
}

