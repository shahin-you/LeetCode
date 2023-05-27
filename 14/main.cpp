#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

void runTests();
string longestCommonPrefix(const vector<string>& strs);

int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(longestCommonPrefix(vector<string>{}) == "");
	assert(longestCommonPrefix(vector<string>{"a","b"}) == "");
	assert(longestCommonPrefix(vector<string>{"abc"}) == "abc");
	assert(longestCommonPrefix(vector<string>{"flower", "flow", "flight"}) == "fl");
	assert(longestCommonPrefix(vector<string>{"shahin", "shahrokh", "shahbaz"}) == "shah");
	assert(longestCommonPrefix(vector<string>{"shahin", "shahrokh", "shahbaz", "arghavan"}) == "");
	assert(longestCommonPrefix(vector<string>{"aaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaa"}) == "aaaaaaaaaaaaaaa");
	assert(longestCommonPrefix(vector<string>{"aa", "a"}) == "a");
	assert(longestCommonPrefix(vector<string>{"aa", "a", ""}) == "");

}

string longestCommonPrefix(const vector<string>& strs) {
	if (strs.size() == 0)
		return "";
	if (strs.size() == 1)
		return strs[0];
	string result{};
	bool ok{ true };
	int index{ 0 };
	while (ok) {
		char curr = strs[0][index];
		for (int i{ 1 };ok && i<strs.size();i++)
			if (index== strs[i].size() || strs[i][index] != curr)
				ok = false;
		if (ok) {
			result += curr;
			index++;
		}
	}
	return result;
}