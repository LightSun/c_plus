#include <pthread.h>
#include <stddef.h>
#include <cstdlib>//exit
#include <iostream>

#include "../../mylib/logger.h"

using namespace std;

#define NUM_THREADS 5

typedef void (*Fun)(void*);

// 线程的运行函数,函数返回的是函数指针，便于后面作为参数
void *say_hello2(void* threadid){
    int tid = *((int*)threadid);
    logT2("Hello runnob! 线程 id = ", tid);
}

/**
 * need flag : -pthread
 */
void testThread2() {
	logM("=========== testThread2() =============");
	// 定义线程的 id 变量，多个变量使用数组
	pthread_t threads[NUM_THREADS];
	int indexes[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; ++i) {
		indexes[i] = i;
		//参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
		 cout <<"main() : creating thread, " << i << endl;
		int ret = pthread_create(&threads[i], NULL, say_hello2, (void*)&(indexes[i]));
		if (ret != 0) {
			logT2("无法创建线程, error_code = ", ret);
			//exit(0);
		}
	}
	//等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
	pthread_exit(NULL); //main
}
