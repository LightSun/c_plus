#include <stddef.h>
#include <iostream>
#include <unistd.h> //sleep
#include <pthread.h>

#include "../../mylib/logger.h"

using namespace std;

#define NUM_THREADS 5

void *wait(void *t);

/**
 * 连接和分离线程。
 */
void testThread3() {
	logM("=========== testThread3() =============");
	int rc;
	int i;
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	void *status;

	// init attr. and set joinable.
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < NUM_THREADS; i++) {
		cout << "main() : creating thread, " << i << endl;
		rc = pthread_create(&threads[i], NULL, wait, (void *) i);
		if (rc) {
			cout << "Error:unable to create thread," << rc << endl;
		}
	}
	// 删除属性，并等待其他线程
	pthread_attr_destroy(&attr);
	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(threads[i], &status);
		if (rc) {
			cout << "Error:unable to join," << rc << endl;
		}
		cout << "Main: completed thread id :" << i;
		cout << "  exiting with status :" << status << endl;
	}
	cout << "Main: program exiting." << endl;
	pthread_exit(NULL);
}

/**
 * in windows: Sleep(millsecond). <windows.h>
 * in linux: sleep(second)      <unistd.h>
 */
void *wait(void *t) {
	int i;
	long tid;
	tid = (long) t;
	for(i=0;i<1000;i++){
        //mock sleep
	}
	cout << "Sleeping in thread " << endl;
	cout << "Thread with id : " << tid << "  ...exiting " << endl;
	pthread_exit(NULL);
}
