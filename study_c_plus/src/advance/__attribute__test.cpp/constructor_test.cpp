#include <iostream>
//函数属性声明
void breforemain() __attribute__((constructor));
void aftermain() __attribute__((destructor));


void breforemain()
{
    std::cout << "before main function" << std::endl;
}
void aftermain()
{
    std::cout << "after main function" << std::endl;
}

class AAA{
public:
      AAA(){std::cout << "global veriable constructor" << std::endl;}
      ~AAA(){std::cout << "global veriable destructor" << std::endl;}
};

AAA aaa;//全局变量

