#include <iostream>
#include <format>


#include <vector>
#include <cassert>

using namespace std;

void runTests();
vector<int> plusOne(vector<int>& digits);

int main() {
	runTests();
	return 0;
}

void runTests() {
	vector<int> test1{ 1,0 };
	vector<int> result{ 1,1 };
	assert(plusOne(test1) == result);
	test1.clear();
	test1.push_back(1); test1.push_back(9);
	result.clear();
	result.push_back(2); result.push_back(0);
	assert(plusOne(test1) == result);
	test1.clear();
	test1.push_back(9);
	result.clear();
	result.push_back(1); result.push_back(0);
	assert(plusOne(test1) == result);
	test1.clear();
	test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9);
	test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9);
	test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9);
	test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9);
	test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9);
	result.clear();
	result.push_back(1); 
	result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0);
	result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0);
	result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0);
	result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0);
	result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0); result.push_back(0);
	assert(plusOne(test1) == result);
	test1.clear();
	test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9);
	test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9);
	test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9);
	test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9);
	test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(9); test1.push_back(8);
	result.clear();
	result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9);
	result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9);
	result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9);
	result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9);
	result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9); result.push_back(9);
	assert(plusOne(test1) == result);
	test1.clear();
	test1.push_back(0);
	result.clear();
	result.push_back(1);
	assert(plusOne(test1) == result);
	test1.clear();
	test1.push_back(4);
	result.clear();
	result.push_back(5);
	assert(plusOne(test1) == result);
}

vector<int> plusOne(vector<int>& digits) {
	vector<int> result{};
	if (digits.size() == 0) {
		result.push_back(1);
		return result;
	}
	int carry{ 1 };
	int index{ static_cast<int>(digits.size()) - 1 };
	int temp{0};
	while (carry==1 && index>=0)
	{
		temp = digits[index--] + 1;
		carry = temp / 10;
		result.push_back(temp % 10);
	}
	if (index == -1 && carry==1)
		result.push_back(1);
	else while (index >= 0)
		result.push_back(digits[index--]);

	reverse(result.begin(), result.end());
	return result;
}