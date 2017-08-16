#include <iostream>
//函数属性声明
void breforemain() __attribute__((constructor));
void aftermain() __attribute__((destructor));


void breforemain()
{
    std::cout << ">>>>>>>> __attribute__((constructor)) >>>>>>>> before main function" << std::endl;
}
void aftermain()
{
    std::cout << ">>>>>>>> __attribute__((destructor)) >>>>>>>> after main function" << std::endl;
}

class AAA{
public:
      AAA(){std::cout << ">>>>>>>> constructor >>>>>>>> global veriable constructor" << std::endl;}
      ~AAA(){std::cout << ">>>>>>>> constructor >>>>>>>> global veriable destructor" << std::endl;}
};

AAA aaa;//全局变量

