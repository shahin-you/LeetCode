#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
int searchInsert(vector<int>& nums, int target);
void runTests();

int main() {
	runTests();
	return 0;
}

void runTests() {
	vector<int> t1{ 1,3,5,6 };
	assert(searchInsert(t1, 5) == 2);
	assert(searchInsert(t1, 2) == 1);
	assert(searchInsert(t1, 7) == 4);
	assert(searchInsert(t1, 0) == 0);

	vector<int> t2{ 2 };
	assert(searchInsert(t2, 1) == 0);
	assert(searchInsert(t2, 2) == 0);
	assert(searchInsert(t2, 3) == 1);

	vector<int> t3{ 1,3,4,5 };
	assert(searchInsert(t3, 1) == 0);
}

int searchInsert(vector<int>& nums, int target) {
	int start{ 0 }, end{ static_cast<int>(nums.size())-1 };
	int mid{ 0 };
	while (start < end) {
		mid = (end + start) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
			end = mid;
		else
			start = mid+1;
	}
	return target > nums[start] ? start + 1 : start;
}