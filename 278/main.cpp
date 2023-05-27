#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

constexpr int realBadVersion{ 4 };

void runTests();
int firstBadVersion(int n);
bool isBadVersion(int k);
int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(firstBadVersion(5) == 4);
}

bool isBadVersion(int k) {
	return k >= realBadVersion;
}

int firstBadVersion(int n) {
	if (n == 1)
		return 1;
	int start{ 1 }, end{ n };
	int mid; 
	while (start <= end) {
		mid = (start + end) / 2;
		bool isBad = isBadVersion(mid);
		if (isBad && isBadVersion(mid - 1)==false)
			return mid;
		else if (isBad)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return mid;
}