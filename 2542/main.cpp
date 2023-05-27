#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <queue>

using namespace std;

void runTests();
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k);

int main() {
	runTests();
	return 0;
}

void runTests() {
	vector<int> n1{ 1,3,3,2 }, n2{ 2,1,3,4 };
	assert(maxScore(n1, n2, 3) == 12);
}

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
	long long result{ INT_MIN };
    vector<pair<int, int>>sortedVector;
    for (int i{ 0 }; i < nums2.size(); i++) {
        sortedVector.push_back({ nums2[i],i });
    }
    sort(sortedVector.rbegin(), sortedVector.rend());
    long long sum{ 0 };
    priority_queue<int, vector<int>, greater<int>>pq;
    for (int i = 0; i < sortedVector.size(); i++) {
        auto& [a, b] = sortedVector[i];
        sum += nums1[b];
        pq.push(nums1[b]);
        //update maxi if the heap size is k
        if (pq.size() == k)result = max(result, sum * a);
        //maintaining the k-1 maximum element
        if (pq.size() > k - 1) {
            sum -= pq.top();
            pq.pop();
        }
    }
	return result;
}