#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

void runTests();
int reverse(int x);

int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(reverse(123) == 321);
	assert(reverse(1) == 1);
	assert(reverse(11) == 11);
	assert(reverse(INT32_MAX-1) == 0);
	assert(reverse(10000000) == 1);

	assert(reverse(-1) == -1);
	assert(reverse(-123) == -321);
	assert(reverse(-23400000) == -432);
	assert(reverse(INT32_MIN) == 0);

	assert(reverse(1534236469) == 0);
}

int reverse(int x) {
	int result{ 0 };
	while (x != 0) {
		if (result > INT32_MAX / 10 || result < INT32_MIN / 10)
			return 0;
		int d{ x % 10 };
		x /= 10;
		result = result * 10 + d;
	}
	return result;
}