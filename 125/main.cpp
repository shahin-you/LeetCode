#include <iostream>
#include <format>
#include <string>
#include <cassert>
using namespace std;

void runTests();
bool isPalindrome(string s);

int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(isPalindrome(",.	;'{}[]"));
	assert(isPalindrome(",.	;'{}[]I"));
	assert(isPalindrome("J,.	;'{}[]"));
	assert(isPalindrome("J,.	;'{J}[]"));
	assert(isPalindrome("J,.	K;'{J}[]"));
	assert(isPalindrome(",.	;'H{}[]I")==false);
	assert(isPalindrome("A man, a plan, a canal: Panama"));
	assert(isPalindrome(""));
	assert(isPalindrome(" "));
	assert(isPalindrome("race a car")==false);
	assert(isPalindrome("xkx"));
}

bool isPalindrome(string s) {
	int len{ static_cast<int>(s.length()) };
	if (len == 0) return true;
	int startIndex{ 0 }, endIndex{ len - 1 };
	while (startIndex < endIndex) {
		//update indices
		while (startIndex < len && !isalnum(s[startIndex])) startIndex++;
		while (endIndex >=0 && !isalnum(s[endIndex])) --endIndex;

		if (startIndex == len || endIndex < 0)
			break;
		
		if (tolower(s[startIndex++]) != tolower(s[endIndex--]))
			return false;
	}
	return true;
}