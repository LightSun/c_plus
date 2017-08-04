
#include "../../mylib/logger.h"


template <typename T>
void fun(T t){
    logT2("called in fun.h >>> start 测试外部模版template: t = ", t);
}
