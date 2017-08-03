#include <iostream>
using namespace std;

// 第一个命名空间
namespace first_space1 {
void func() {
	cout << "Inside first_space1" << endl;
}
}
// 第二个命名空间
namespace second_space1 {
void func() {
	cout << "Inside second_space1" << endl;
}
}

// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
   // 第二个命名空间
   namespace second_space{
      void func(){
         cout << "Inside second_space" << endl;
      }
   }
}
using namespace first_space::second_space;


void testNamespace() {

	// 调用第一个命名空间中的函数
	first_space1::func();

	// 调用第二个命名空间中的函数
	second_space1::func();

	func(); // 省略 first_space::second_space;
}
