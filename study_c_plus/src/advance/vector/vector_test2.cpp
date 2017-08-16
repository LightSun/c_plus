
#include <vector>
#include <list>
#include <utility>
//#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iterator>

#include "../../mylib/logger.h"
#include "../../mylib/util.h"

void testCreateVector();
void testVectorDelete();

/** using vector
 * https://stackoverflow.com/documentation/c%2b%2b/511/stdvector#t=201708160307562153034
 */
void test2_Vector(){
	testCreateVector();
	testVectorDelete();
}

void testVectorDelete(){
	std::vector<int> v{ 1, 2, 3 };
	v.pop_back();                           // v becomes {1, 2}
	//clear all elements
	std::vector<int> v2{ 1, 2, 3 };
	v2.clear();
    //delete element which index is 3
	std::vector<int> v3{ 1, 2, 3, 4, 5, 6 };
	v3.erase(v3.begin() + 3);                 // v becomes {1, 2, 3, 5, 6}

	//delete element in range
	std::vector<int> v4{ 1, 2, 3, 4, 5, 6 };
	v4.erase(v4.begin() + 1, v4.begin() + 5);  // v becomes {1, 6}

	//delete element by value
	//std::vector<int> v5{ 1, 1, 2, 2, 3, 3 };
	//int value_to_remove = 2;
	//v5.erase(std::remove(v5.begin(), v5.end(), value_to_remove), v5.end()); // v becomes {1, 1, 3, 3}
}

void testCreateVector() {
	logM("=========== Start test create Vector =============");
	std::vector<int> v0(4); // v becomes {0, 0, 0, 0}
	//create vector from other vector
	std::vector<int> v(v0);
	std::vector<int> v1 = v;
	//std::vector<int> v2(std::move(v1)); //in eclise can't resolve why?
	logT2("create vector. std::vector<int> v(v0): ", toString(v));
	logT2("create vector. std::vector<int> v1 = v : ", toString(v1));
	// from another vector
	std::vector<int> v2(v1.begin(), v1.begin() + 3);
	logT2("create vector. std::vector<int> v2(v1.begin(), v1.begin() + 3) : ",
			toString(v2));
	// from an array
	int z[] = { 1, 2, 3, 4 };
	std::vector<int> v3(z, z + 3);
	logT2("create vector. std::vector<int> v3(z, z + 3) : ", toString(v3));
	// from a list
	std::list<int> list1 { 1, 2, 3 };
	std::vector<int> v4(list1.begin(), list1.end()); // v becomes {1, 2, 3}
	logT2("create vector.std::vector<int> v4(list1.begin(), list1.end()) : ",
			toString(v4));
	//eclipse can't resolved.
	/* // from another vector
	 std::vector<int> v5(std::make_move_iterator(v2.begin()),
	 std::make_move_iterator(v2.end()));

	 // from a list
	 std::list<int> list2{ 1, 2, 3 };
	 std::vector<int> v6(std::make_move_iterator(list2.begin()),
	 std::make_move_iterator(list2.end()));*/
	//assign make vector reinit.
	v.assign(4, 100); // v becomes {100, 100, 100, 100}
	v.assign(v2.begin(), v2.begin() + 3); // v becomes {v2[0], v2[1], v2[2]}

	v.assign(z + 1, z + 4); // v becomes {2, 3, 4}
}





