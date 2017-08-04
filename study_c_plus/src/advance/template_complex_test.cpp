
/**
 * 复杂的模版+结构体+typedef.
 * 模版和泛型的高级运用
 */

//#include <cstdlib>

/** like
#ifndef _GLIBCXX_CONSTEXPR
# if __cplusplus >= 201103L
#  define _GLIBCXX_CONSTEXPR constexpr
#  define _GLIBCXX_USE_CONSTEXPR constexpr
# else
#  define _GLIBCXX_CONSTEXPR
#  define _GLIBCXX_USE_CONSTEXPR const
# endif
#endif
 */

#include "../mylib/logger.h"
/**
 * #if xxx 后面的xxx一般是一个宏，需要在编译前给一个定义，
 * 如何没有通过#define进行定义xxx的话，将不会编译#if xxx 后续代码（到#endif或是#elseif）.
 */
#ifndef __com_heaven7_cplus__
# define __com_heaven7_cplus__
#endif

#define __com_heaven7_cplus__default

#define ns_heaven7(v)  __com_heaven7_cplus__ ## v  //相当于连接字符串 __com_heaven7_cplus__{$v}

template <typename T>
struct  TestSt0{

	 typedef unsigned long  int_type;
};


template <typename T>
struct TestSt1{

    typedef T type;
    typedef typename TestSt0<T>::int_type int_type;

	static void method1(const int_type& t1);

	static __com_heaven7_cplus__ int method2(const int_type& t1){

	   return static_cast<type>(t1);
	}

	static const type* method3(const int_type& t1);

};

//template<typename T2, typename T = TestSt1<T> > //这样写是错误的
template<typename T2, typename T = TestSt1<T2> >
    class TestClass1{
    public :
	typedef T2 t2;
	typedef T t1;

	static const t1* method3(const t2& ct2);

	static void method1(const t2& ct2){

	}
};
template<typename T1, typename T2>
   class TestClass2{

};
//extern 表示 不要在该编译单元内  实例化模版。
extern template class TestClass1<char>; //extern 定义可在外部
extern template class TestClass2<char, wchar_t>;

//=================== 更复杂的   =================
namespace heaven7 ns_heaven7(default){
	template<typename T1, typename T2>
	   class TestClass3{

	};
	extern template class TestClass3<char, wchar_t>;
}


//========================= some impl ====================================

// 实现struct TestSt1 的m1 方法
template <typename T>
	 void
	 TestSt1<T>::method1(const int_type& t1){
	 logM("TestSt1__ method1(return void) is implemented.");
}

template<typename T>
   const typename TestSt1<T>::type*  //返回值类型
   TestSt1<T>::method3(const int_type& t1){
   logM("TestSt1__ method3(return typename TestSt1<T>::type* ) is implemented.");
}


