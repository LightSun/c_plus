#include "../../mylib/logger.h"

void test_ReinpreterCast() {

	int n = 9;
	// reinterpret_cast 仅仅是复制 n 的比特位到 d，因此d 包含无用值。
	double d = reinterpret_cast<double&>(n);

	logT2("called [ test_ReinpreterCast() ]: n = " + object2String(n),
			", d = " + object2String(d));
}
