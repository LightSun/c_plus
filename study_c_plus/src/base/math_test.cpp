#include <cmath> //数学库
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int testMath() {
	int i, j;

	// 设置种子
	srand((unsigned) time( NULL));

	/* 生成 10 个随机数 */
	for (i = 0; i < 10; i++) {
		// 生成实际的随机数
		j = rand();
		cout << "随机数： " << j << endl;
	}
	return 0;
}