#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

void runTests();
string countAndSay(int n);

int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(countAndSay(1) == "1");
	assert(countAndSay(2) == "11");
	assert(countAndSay(3) == "21");
	assert(countAndSay(4) == "1211");
	assert(countAndSay(5) == "111221");
	assert(countAndSay(6) == "312211");
}

string countAndSay(int n) {
	if (n == 1)
		return "1";
	string prevSay = countAndSay(n - 1);
	//say n-1:
	int count;
	string result{ "" };
	int len = prevSay.size();
	for (int index{ 0 }; index < len; index+=count) {
		count = 1;
		while (index+count <len && prevSay[index] == prevSay[index + count])
			count++;
		result += to_string(count) + prevSay[index];
	}
	return result;

}