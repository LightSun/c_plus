
#include "fun.h"

/**
 * extern 告诉编译器. 不要在该编译单元内将该模板实例化。---------提高性能
 */
extern template void fun<int>(int);

void testOut_template2(){
    fun<int>(2);
}
