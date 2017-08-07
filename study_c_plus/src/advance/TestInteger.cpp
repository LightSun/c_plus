
//模拟整型Integer
class TestInteger
{
public:
	TestInteger(int ival) : value(ival) {

	}
	TestInteger(const TestInteger& iobj) : value(iobj.value) {

	}

    // operator int() { return value; } // conversion to built-in int

	TestInteger operator+() const { return TestInteger(value); }
	TestInteger operator-() const { return TestInteger(-value); }

	TestInteger operator+(const TestInteger& rhs) const { return TestInteger(value + rhs.value); }
	TestInteger operator-(const TestInteger& rhs) const { return TestInteger(value - rhs.value); }
    TestInteger operator*(const TestInteger& rhs) const { return TestInteger(value * rhs.value); }
    TestInteger operator/(const TestInteger& rhs) const { return TestInteger(value / rhs.value); }
    TestInteger operator%(const TestInteger& rhs) const { return TestInteger(value % rhs.value); }

    // prefix
    TestInteger operator++() { return TestInteger(++value); }
    TestInteger operator--() { return TestInteger(--value); }

    // suffix
    TestInteger operator++(int) { int old = value; value++; return TestInteger(old); }
    TestInteger operator--(int) { int old = value; value--; return TestInteger(old); }

    // compare:
    bool operator<(const TestInteger& rhs) const { return value < rhs.value; }
    bool operator>(const TestInteger& rhs) const { return value > rhs.value; }
    bool operator==(const TestInteger& rhs) const { return value == rhs.value; }
    bool operator!=(const TestInteger& rhs) const { return value != rhs.value; }
    bool operator<=(const TestInteger& rhs) const { return value <= rhs.value; }
    bool operator>=(const TestInteger& rhs) const { return value >= rhs.value; }

    // bit operations:
    TestInteger operator~() const { return TestInteger(~value); }
    TestInteger operator<<(unsigned n) const { return TestInteger(value << n); }
    TestInteger operator>>(unsigned n) const { return TestInteger(value >> n); }
    TestInteger operator&(const TestInteger& rhs) const { return TestInteger(value & rhs.value); }
    TestInteger operator|(const TestInteger& rhs) const { return TestInteger(value | rhs.value); }
    TestInteger operator^(const TestInteger& rhs) const { return TestInteger(value ^ rhs.value); }

    // assignment:
    TestInteger operator=(const TestInteger& rhs) { return value = rhs.value; }
    // compound assignment:
    TestInteger operator+=(const TestInteger& rhs) { return value += rhs.value; }
    TestInteger operator-=(const TestInteger& rhs) { return value -= rhs.value; }
    TestInteger operator*=(const TestInteger& rhs) { return value *= rhs.value; }
    TestInteger operator/=(const TestInteger& rhs) { return value /= rhs.value; }
    TestInteger operator%=(const TestInteger& rhs) { return value %= rhs.value; }
    TestInteger operator&=(const TestInteger& rhs) { return value &= rhs.value; }
    TestInteger operator|=(const TestInteger& rhs) { return value |= rhs.value; }
    TestInteger operator^=(const TestInteger& rhs) { return value ^= rhs.value; }
    TestInteger operator<<=(const TestInteger& rhs) { return value <<= rhs.value; }
    TestInteger operator>>=(const TestInteger& rhs) { return value >>= rhs.value; }
// private:
    int value;
};
