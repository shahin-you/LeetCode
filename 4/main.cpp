#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

void runTests();
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main() {
	runTests();
	return 0;
}

void runTests() {
	//so easy that we didn't even need any tests! :D
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int i1{ 0 }, i2{ 0 };
	vector<int> merged{};
	while (i1 < nums1.size() && i2 < nums2.size()) {
		if (nums1[i1] < nums2[i2])
			merged.push_back(nums1[i1++]);
		else 
			merged.push_back(nums2[i2++]);
	}
	while (i1 < nums1.size())
		merged.push_back(nums1[i1++]);
	while (i2 < nums2.size())
		merged.push_back(nums2[i2++]);
	int len = merged.size();
	return len % 2 == 0 ? (merged[len / 2] + merged[len / 2 - 1]) / 2.0 : static_cast<double>(merged[len/2]);
}