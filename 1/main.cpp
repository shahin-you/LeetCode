#include <iostream>
#include <format>
#include <map>
#include <vector>

#include <cassert>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);
template<typename T>
bool isEqual(vector<T> const& v1, vector<T> const& v2);
void runTests();

int main() {
	runTests();
	return 0;
}

void runTests() {
	vector<int> sample1{ 8,3,2,15,-1, 32768 };
	assert(isEqual<int>(twoSum(sample1, 1), vector<int>{2, 4}));
	assert(isEqual<int>(twoSum(sample1, 32771), vector<int>{1, 5}));
	assert(isEqual<int>(twoSum(sample1, 32776), vector<int>{0, 5}));
	assert(isEqual<int>(twoSum(sample1, 5), vector<int>{1, 2}));

	vector<int> sample2{ 0,1 };
	assert(isEqual<int>(twoSum(sample2, 1), vector<int>{0, 1}));

	vector<int> sample3{ INT_MAX, 1,2,-1, INT_MIN  };
	assert(isEqual<int>(twoSum(sample3, 3), vector<int>{1, 2}));
	assert(isEqual<int>(twoSum(sample3, INT_MAX + INT_MIN), vector<int>{0, 4}));

}

template<typename T>
bool isEqual(vector<T> const& v1, vector<T> const& v2) {
	return (v1.size() == v2.size() &&
			equal(v1.begin(), v1.end(), v2.begin()));
}

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result{};
	map<int, int> ctoi{};
	for (int i{ 0 }; i < nums.size();i++) {
		auto mapResult = ctoi.find(nums[i]);
		if (mapResult != ctoi.end()) {
			result.push_back(mapResult->second);
			result.push_back(i);
			break;
		}
		ctoi[target-nums[i]] = i;
	}
	return result;
}