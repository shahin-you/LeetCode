#include <iostream>
#include <format>

#include <cassert>
#include <string>
#include <algorithm>

using namespace std;


void runTests();
int myAtoi(string s);

int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(myAtoi("                                                                    -1") == -1);
	assert(myAtoi("") == 0);
	assert(myAtoi("     ") == 0);
	assert(myAtoi("     -    1") == 0);
	assert(myAtoi("     +135555") == 135555);
	assert(myAtoi("     -991.1") == -991);
	assert(myAtoi("     111111111111111111111111111111111111111111111111111111111") == static_cast<unsigned int>(1 << 31) - 1);
	assert(myAtoi("     -111111111111111111111111111111111111111111111111111111111") == 1<<31);
	assert(myAtoi("42") == 42);
	assert(myAtoi("     -42") == -42);
	assert(myAtoi("-4193 with words") == -4193);
}

int myAtoi(string s) {
	signed long long result{ 0 };
	int index{ 0 };
	int sign{ 1 };
	s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {return ch != ' '; }));
	if (s.length() == 0)
		return 0;

	if (s[0] == '-' || s[0]=='+') {
		if (s[0]=='-')
			sign = -1;
		s.erase(s.begin(), s.begin() + 1);
	}
	int len{ static_cast<int>(s.length()) };
	while (index < len && isdigit(s[index])) {
		result = result * 10 + (s[index++] - '0');
		if (result > 2147483647) {
			switch (sign) {
			case 1:
				return 2147483647;
			default:
				return -2147483648;
			}
		}
	}

	return static_cast<int>(sign*result);
}