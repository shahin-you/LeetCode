#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

void runTests();
bool containsDuplicate(const vector<int>& nums);

int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(containsDuplicate({ 1,2,3 }) == false);
	assert(containsDuplicate({ 1 }) == false);
	assert(containsDuplicate({ 1,2,3,1 }));
	assert(containsDuplicate({ 1,2,3,4 }) == false);
	assert(containsDuplicate({ 1,1,1,3,3,4,3,2,4,2 }));
}

bool containsDuplicate(const vector<int>& nums) {
	map<int, int> presenceMap{};
	for (const int n : nums)
		if (presenceMap[n]>0)
			return true;
		else
			presenceMap[n]++;
	return false;
}