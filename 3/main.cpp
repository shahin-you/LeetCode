#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

void runTests();
int lengthOfLongestSubstring(string s);

int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(lengthOfLongestSubstring("") == 0);
	assert(lengthOfLongestSubstring("a") == 1);
	assert(lengthOfLongestSubstring("abcabbc") == 4);
	assert(lengthOfLongestSubstring("bcabcd") == 4);
	assert(lengthOfLongestSubstring(" this is a test") == 13);
	assert(lengthOfLongestSubstring("aabbcc") == 1);
	assert(lengthOfLongestSubstring(".aabbcc.") == 7);
	assert(lengthOfLongestSubstring("bbbbbbbbbbbbbbbbbbbb") == 1);
	assert(lengthOfLongestSubstring("abcabcbb") == 3);
	assert(lengthOfLongestSubstring("pwka") == 4);

}

int lengthOfLongestSubstring(string s) {
	int maxLen{ 0 };
	map<char, pair<int,int>> visited{};
	for (int i{ 0 }; i < s.length(); i++) {
		if (visited.count(s[i])) {
			if (i - visited[s[i]].first > visited[s[i]].second) 
				visited[s[i]].second = i - visited[s[i]].first;
		}
		else
			visited[s[i]].second = 0;
		visited[s[i]].first = i;
	}
	for (const auto& elem : visited) {
		int currentLen = elem.second.second == 0 ? s.length() - elem.second.first : elem.second.second;
		if (currentLen > maxLen)
			maxLen = currentLen;
	}
	return maxLen;
}