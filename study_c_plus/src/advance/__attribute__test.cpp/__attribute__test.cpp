/**
 * If you wish to do the same for all the structures,
 *  simply we can push the alignment value to stack using #pragma
#pragma pack(push, 1)
//Structure 1
......
//Structure 2
......
#pragma pack(pop)
 */
//=========================== __attribute__ ======== test =============
#include <stdio.h>
#include "../../mylib/logger.h"

/**
 * sizeof(a)+sizeof(b)+sizeof(c)=4+1+2=7<8 所以sizeof(pp)=8
 */
struct p {

	int a;

	char b;

	short c;

}__attribute__((aligned(4))) pp; //8

/**
 * sizeof(a)+sizeof(b)+sizeof(c)=1+4+2=7
但是 a 后面需要用 3 个字节填充，但是 b 是 4 个字节，
所以 a 占用 4 字节， b 占用 4 个字节，而 c 又要占用 4 个字节。所以 sizeof(mm)=12
 */
struct m {

	char a;
	int b;
	short c;

}__attribute__((aligned(4))) mm; //12

struct m2 {
	char a;
	int b;
	short c;

}__attribute__((aligned)) mm2;

/**
 * 因为默 认是以4 字节对齐，所以sizeof(oo)=8
 */
struct o {

	int a;
	char b;
	short c;

} oo; //8

/**
sizeof(xx):
sizeof(a)+ sizeof(b)=4+1=5
sizeof(pp)=8; 即xx 是采用8 字节对齐的，所以要在a ，b 后面添3 个空余字节，然后才能存储px ，
4+1+ （3 ）+8+1=17
因为xx 采用的对齐是8 字节对齐，所以xx 的大小必定是8 的整数倍，即xx 的大小是一个比17 大又是8 的倍数的一个最小值，由此得到
17<24 ，所以sizeof(xx)=24
 */
struct x {

	int a;

	char b;

	struct p px;

	short c;

}__attribute__((aligned(8))) xx; //24



//packed  structure 已经padding了。编译器不再padding.
typedef struct{
     char Data1;  //填充3个字节
     int Data2;
     unsigned short Data3;
     char Data4;

}__attribute__((packed, aligned(1))) SampleStruct1; //11

typedef struct{
     char Data1;
     int Data2;
     unsigned short Data3;
     char Data4;

}__attribute__((packed, aligned(2))) SampleStruct2;//12

typedef struct{
     char Data1;
     int Data2;
     unsigned short Data3;
     char Data4;

}__attribute__((packed, aligned(4))) SampleStruct3;//12
typedef struct{
     char Data1;
     int Data2;
     unsigned short Data3;
     char Data4;

}__attribute__((packed, aligned(8))) SampleStruct4;//16


/**
 *   GNU C 的一大特色就是__attribute__ 机制。
 *   __attribute__ 可以设置函数属性（Function Attribute ）、变量属性（Variable Attribute ）和类型属性（Type Attribute ）。
 */
void testAttribute() {
	logM("========= start testAttribute() ===============");

	printf("sizeof(int)=%d,sizeof(short)=%d.sizeof(char)=%d\n", sizeof(int),
			sizeof(short), sizeof(char));
	printf("pp=%d,mm=%d , mm2 = %d\n", sizeof(pp), sizeof(mm), sizeof(mm2));
	printf("oo=%d,xx=%d \n", sizeof(oo), sizeof(xx));
	printf("SampleStruct1=%d, SampleStruct4=%d, SampleStruct3=%d \n",
			sizeof(SampleStruct1), sizeof(SampleStruct4), sizeof(SampleStruct3));
     /**
sizeof(int)=4,sizeof(short)=2.sizeof(char)=1
pp=8,mm=12
oo=8,xx=24
      */
}
