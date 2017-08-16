#include <vector>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iterator>

#include "../../mylib/logger.h"
#include "../../mylib/util.h"

/**
 * 测试vector 相关api
 */
void testVector2();
void testVector3();
//use pointer
void testVector4();

void testVectorIterator();

void testVector() {
	logM("============ start testVector() ===============");
	std::vector<int> v{1,2,3};

	// using []
	int a = v[1];    // a is 2
	v[1] = 4;        // v now contains { 1, 4, 3 }

	// using at()  , like java list.get(index)
	int b = v.at(2); // b is 3
	v.at(2) = 5;     // v now contains { 1, 4, 5 }
	//int c = v.at(3); //must throws std::out_of_range exception

	for (std::size_t i = 0; i < v.size(); ++i) {
		v[i] = 1;
	}
	testVector2();
	testVector3();
}

void testVector3() {
	std::vector<int> v;
	int sum(0);

	for (int i = 1; i <= 10; i++) {
		v.push_back(i); //create and initialize the vector
	}

	logT2("after push_back: vector is ", toString(v));

	while (!v.empty()) //loop through until the vector tests to be empty
	{
		sum += v.back(); //keep a running total
		v.pop_back(); //pop out the element which removes it from the vector
	}

	cout << "total: " << sum << '\n'; //output the total to the user
}

void testVector2() {
	vector<int> v { 4, 5, 6 }; // In pre-C++11 this is more verbose .-std=c++11
/*
	vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
*/

	//front is the first element of vector. like. java list.get(0).
	int a = v.front();   // a is 4, v.front() is equivalent to v[0]
	v.front() = 3;       // v now contains {3, 5, 6}
	//back is the last element.
	int b = v.back();    // b is 6, v.back() is equivalent to v[v.size() - 1]
	v.back() = 7;        // v now contains {3, 5, 7}
}

void testVector4(){
	std::vector<int> v{ 1, 2, 3, 4 }; // v contains {1, 2, 3, 4}
	int* p = v.data(); // p points to 1(first element)
	*p = 4;            // v now contains {4, 2, 3, 4}
	//指针p位移1个单位
	++p;               // p points to 2 (second element).
	*p = 3;            // v now contains {4, 3, 3, 4}
	p[1] = 2;          // v now contains {4, 3, 2, 4}
	*(p + 2) = 1;      // v now contains {4, 3, 2, 1}
}

void testVectorIterator(){
	std::vector<int> v{ 4, 5, 6 };

	//it is a pointer
	auto it = v.begin();
	int i = *it;        // i is 4
	++it;
	i = *it;            // i is 5
	*it = 6;            // v contains { 4, 6, 6 }
	auto e = v.end();   // e points to the element after the end of v. It can be
	                    // used to check whether an iterator reached the end of the vector:
	++it;
	it == v.end();      // false, it points to the element at position 2 (with value 6)
	++it;
	it == v.end();      // true

	//==============================================

	std::vector<int> v2{ 1, 2, 3 };
	int* p = v2.data() + 1;     // p points to 2
	v2.insert(v2.begin(), 0);    // p is now invalid, accessing *p is a undefined behavior.
	p = v2.data() + 1;          // p points to 1
	v2.reserve(10);             // p is now invalid, accessing *p is a undefined behavior.
	p = v2.data() + 1;          // p points to 1
	v2.erase(v2.begin());        // p is now invalid, accessing *p is a undefined behavior.

	// Different from std::vector<int> v{3, 6} in C++11
	std::vector<int> v3(3, 6);  // v3 becomes {6, 6, 6}

	std::vector<int> v4(4);     // v4 becomes {0, 0, 0, 0}
}
