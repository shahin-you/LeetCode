#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

void runTests();
int strStr(string haystack, string needle);
int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(strStr("sadbutsad", "sad") == 0);
	assert(strStr("sadbutsad", "a") == 1);
	assert(strStr("sadbutsad", "s") == 0);
	assert(strStr("sadbutsad", "sadssssssssss") == -1);
	assert(strStr("leetcode", "oe") == -1);
	assert(strStr("a", "a") == 0);

}

int strStr(string haystack, string needle) {
	if (haystack.length() < needle.length())
		return -1;
	for (int i{0};i<=haystack.length() - needle.length();i++)
		if (haystack[i] == needle[0]) {
			bool found{ true };
			for (int j{ 1 }; j < needle.length() && found; j++)
				found &= needle[j] == haystack[j + i];
			if (found)
				return i;
		}
	return -1;
}