
/**
 * c++ 内联函数: 通常与类一起使用。 如果函数是内联的，编译器会把函数的代码副本防止到每个调用该函数的地方。（类似android include）
 * 对于内联函数的任意修改， 都需要重新编译所有。因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。
 * 关键字 inline
 * 在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。
 *
 * 内联使用准则：
 *  1.在内联函数内不允许使用循环语句和开关语句；
	2.内联函数的定义必须出现在内联函数第一次调用之前；
	3.类结构中所在的类说明内部定义的函数是内联函数。
	结论: 一个较为合理的经验准则是, 不要内联超过 10 行的函数. 谨慎对待析构函数, 析构函数往往比其表面看起来要更长, 因为有隐含的成员和基类析构函数被调用!
*/
#include <iostream>

using namespace std;

//这里attribute 表示强制使用inline(内联)
extern inline int max(int x, int y)__attribute__((always_inline));

int max(int x, int y){
   return (x > y)? x : y;
}

void testInline( ){
   cout << "Max (20,10): " << max(20,10) << endl;
   cout << "Max (0,200): " << max(0,200) << endl;
   cout << "Max (100,1010): " << max(100,1010) << endl;
}
