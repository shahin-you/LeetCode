#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

void runTests();
vector<int> topKFrequent(const vector<int>& nums, int k);

int main() {
	runTests();
	return 0;
}

void runTests() {
	vector<int> v1{ topKFrequent(vector<int>{1, 2,3}, 1) }, v2{1};
	assert(equal(v1.begin(), v1.end(), v2.begin()));

	vector<int> v3{ topKFrequent(vector<int>{1, 2,2}, 1) }, v4{ 2 };
	assert(equal(v3.begin(), v3.end(), v4.begin()));

	vector<int> v5{ topKFrequent(vector<int>{1,1,1,2,2,3}, 2) }, v6{ 1,2 };
	assert(equal(v5.begin(), v5.end(), v6.begin()));

	vector<int> v7{ topKFrequent(vector<int>{1, 2}, 2) }, v8{ 1,2 };
	assert(equal(v7.begin(), v7.end(), v8.begin()));
}

vector<int> topKFrequent(const vector<int>& nums, int k) {
	vector<int> result{};
	if (nums.size() == 0)
		return result;

	map<int, int> counter{};
	for (const int& num : nums)
		counter[num]++;

	auto compairer = [](pair<int, int>l, pair<int, int>r) {
		if (l.second == r.second)
			return l.first > r.first;
		return l.second < r.second;
		//return r.second == l.second ? l.first < r.first : l.second < r.second;
	};
	priority_queue < pair<int, int>, vector<pair<int, int>>, decltype(compairer)> pq(counter.begin(), counter.end(), compairer);
	for (int i{ 0 }; i < k; i++) {
		result.push_back(pq.top().first);
		pq.pop();
	}
	return result;
}