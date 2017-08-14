#include <stdio.h>

/**
 * 结构体的有效对齐值的确定：

1）当未明确指定时，以结构体中最长的成员的长度为其有效值

2）当用#pragma pack(n)指定时，以n和结构体中最长的成员的长度中较小者为其值。

3）当用__attribute__ ((__packed__))指定长度时，强制按照此值为结构体的有效对齐值

4) __attribute__((aligned ))----> “让编译器根据目标机制采用最大最有益的方式对齐"使用的16字节对齐.

5)__attribute__ ((packed))的作用就是告诉编译器取消结构在编译过程中的优化对齐,
   按照实际占用字节数进行对齐，是GCC特有的语法
 */

struct A1 {
}; //1

struct A2 {
	;
}; //1

struct A3 {     //以8为有效对齐基数. 8k
	char a; // 1
	int b; // 4
	unsigned short c; // 2
	long d; // 4
	unsigned long long e; // 8
	char f; // 1
};

/**
 * 无指定，默认以最大成员大小8为对齐方式。
 * b,a,c 一起对齐为8个字节。
 * d 本来4个字节。 自动提升为8.
 * f同理
 */
struct A4 {    //32
	int b;
	char a;
	unsigned short c;
	long d;
	unsigned long long e;
	char f;
};

/**
 * 指明'#pragma pack'时，对齐的值 为 最小值（‘#pragma pack’ 和 最大成员大小的).
 * 这里因  2 < 8(最大成员大小). 所以取2.
 */
//pragma pack(n)
//alignment must be a power of two
#pragma pack(2)//指定按两字节对齐
struct B1 {         //22
	char a;  //2
	int b;   //4
	unsigned short c; //2
	long d;  //4
	unsigned long long e; //8
	char f;  //2
};
#pragma pack()//取消指定对齐

/**
 * 因 4 < 8 取 4.
 */
#pragma pack(4)
struct B2 {      //28
	char a;  //4
	int b;   //4
	unsigned short c;  //4
	long d;            //4
	unsigned long long e; //8
	char f;    //4
};
#pragma pack()

/**
 * 因 8 = 8. 取 8
 * a,b 一起对齐 为8
 * c,d 一起对齐为8
 * e  8
 * f 对齐为8
 */
#pragma pack(8)
struct B3 {  //32
	char a;
	int b;
	unsigned short c;
	long d;
	unsigned long long e;
	char f;
};
#pragma pack()

/**
 * 16 > 8 取 8
 * a,b 对齐为8
 * c, d对齐为8
 * e   8
 * f 对齐为8
 */
#pragma pack(16)
struct B4 {   //32
	char a;
	int b;
	unsigned short c;
	long d;
	unsigned long long e;
	char f;
};
#pragma pack()

/**
 * '__attribute__' 指定时强制按照该值对齐。
 * 按照16对齐
 *
 */
//============__attribute__========================
struct C1 {        //32
	char a;  //4
	int b;   //4
	unsigned short c; //4
	long d;  //4
	unsigned long long e; //8
	char f;  //8
}__attribute__((aligned));

/**
 * a,b 一起对齐为 8
 * c,f 一起对齐为8
 */
struct C2 {      //16
	char a;  //4
	int b;   //4
	unsigned short c; // 2
	//long d;
	//unsigned long long e;
	char f; //6
}__attribute__((aligned));

/**
 *  16字节对齐
 C3中成员位置分别为
 a:0,
 b:4,
 c:8,
 d:12,
 f:16,
 f也就是位于16-19, 为了满足16字节对齐,所以20-31被用于对齐了,所以占32字节,
 */
struct C3 {       //32
	char a;
	int b;
	unsigned short c;
	long d;
	//unsigned long long e;
	char f;
}__attribute__((aligned));

struct C4 {      //32
	char a;
	//int b;
	unsigned short c;
	//long d;
	unsigned long long e;
	char f;
}__attribute__((aligned));

struct C5 {       //16
	char a;
	//int b;
	//unsigned short c;
	//long d;
	//unsigned long long e;
	//char f;
}__attribute__((aligned));

struct D1 {       //32
	char a;
	int b;
	unsigned short c;
	long d;
	unsigned long long e;
	char f;
}__attribute__((aligned(1)));

struct D2 {      //32
	char a;
	int b;
	unsigned short c;
	long d;
	unsigned long long e;
	char f;
}__attribute__((aligned(4)));

struct D3 {     //32
	char a;
	int b;
	unsigned short c;
	long d;
	unsigned long long e;
	char f;
}__attribute__((aligned(8)));

struct D4 {      //32
	char a;
	int b;
	unsigned short c;
	long d;
	unsigned long long e;
	char f;
}__attribute__((aligned(16)));

struct E1 {       //25
	char a;
	int b;
	unsigned short c;
	long d;
	unsigned long long e;
	char f;
}__attribute__((packed));

void testPragmaPack() {
	printf("============ start testPragmaPack() ================\n");
	unsigned long long value = 1;
    printf("sizeof(unsigned long long) = %d\n", sizeof(value));
	printf(
			"sizeof(A1):%2d...sizeof(A2):%2d...sizeof(A3):%2d...sizeof(A4):%2d\n\r",
			sizeof(struct A1), sizeof(struct A2), sizeof(struct A3),
			sizeof(struct A4));

	printf(
			"sizeof(B1):%2d...sizeof(B2):%2d...sizeof(B3):%2d...sizeof(B4):%2d\n\r",
			sizeof(struct B1), sizeof(struct B2), sizeof(struct B3),
			sizeof(struct B4));

	printf(
			"sizeof(C1):%2d...sizeof(C2):%2d...sizeof(C3):%2d...sizeof(C4):%2d...sizeof(C5):%2d\n\r",
			sizeof(struct C1), sizeof(struct C2), sizeof(struct C3),
			sizeof(struct C4), sizeof(struct C5));

	printf(
			"sizeof(D1):%2d...sizeof(D2):%2d...sizeof(D3):%2d...sizeof(D4):%2d\n\r",
			sizeof(struct D1), sizeof(struct D2), sizeof(struct D3),
			sizeof(struct D4));

	printf("sizeof(E1):%2d...\n\r", sizeof(struct E1));
}
