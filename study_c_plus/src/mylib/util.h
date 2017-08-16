#include <string>
#include <iterator>
#include <iostream>
#include <sstream>
using namespace std;

/**
 *
 */
template<typename T> string toString(std::vector<T> vec) {

	std::ostringstream oss;

	if (!vec.empty()) {
		// Convert all but the last element to avoid a trailing ","
		//std::copy 容器拷贝函数. 量大的时候比for循环高校
		std::copy(vec.begin(), vec.end() - 1,
				std::ostream_iterator<int>(oss, ","));

		// Now add the last element with no delimiter
		oss << vec.back();
	}
	return oss.str();
}
