#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

void runTests();
bool judge(vector<int>& nums, int val, int expected);
int removeElement(vector<int>& nums, int val);

int main() {
	runTests();
	return 0;
}

void runTests() {
	vector<int> test1{};
	assert(judge(test1, 10, 0));

	vector<int> test2{ 3,2,2,3 };
	assert(judge(test2, 3, 2));

	vector<int> test3{ 0,1,2,2,3,0,4,2 };
	assert(judge(test3, 2, 5));

	vector<int> test4{0,0,0,0,0,0};
	assert(judge(test4, 0, 0));

	vector<int> test5{ 0,0,5,4,2,1 };
	assert(judge(test5, 0, 4));

	vector<int> test6{ 1,1,1,2,1,1 };
	assert(judge(test6, 1, 1));
}

bool judge(vector<int>& nums, int val, int expected) {
	int orgSize = nums.size();
	vector<int> copy(nums);
	int returned = removeElement(nums, val);
	if (returned != expected || orgSize!=nums.size())
		return false;
	if (returned == 0)
		return true;
	sort(copy.begin(), copy.end());
	auto it1 = nums.begin(), it2 = copy.begin();
	while (it1 != nums.end() && it2 != copy.end()) {
		if (*it2 == val) {
			it2++;
			continue;
		}
		if (*it1 != *it2) return false;
		it1++;
		it2++;
	}
	return true;
}

int removeElement(vector<int>& nums, int val) {
	if (nums.size() == 0)
		return 0;
	int result{ static_cast<int>(nums.size()) };
	sort(nums.begin(), nums.end());
	auto it = lower_bound(nums.begin(), nums.end(), val);
	while (it != nums.end() &&  *it == val) {
		*it = INT_MAX;
		result--;
		it++;
	}
	sort(nums.begin(), nums.end());
	return result;
}