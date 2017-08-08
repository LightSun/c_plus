
class TAttriFoo {
public:
	// 类似java的标记过时
	void my_func() __attribute__((deprecated)) {
	}

	/**
	 * noinlie = no inline : 通知编译器不要内联这个函数。
	 * __attribute__((__always_inline__)) 总是内联
	 *
	 */
	void my_func2() __attribute__((noinline)) {
	}

};

void testClassAttribute3(){
	TAttriFoo f;
	f.my_func();
	f.my_func2();
}

/**
 * 一般。先定义的先初始化。
 * 但是用了init_priority 就不一定了
 */
//给对象 初始化的优先级.
TAttriFoo  A  __attribute__ ((init_priority (2000)));
TAttriFoo  B  __attribute__ ((init_priority (543)));
