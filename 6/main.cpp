#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

void runTests();
string convert(string s, int numRows);

int main() {
	runTests();
	return 0;
}

void runTests() {
    assert(convert("A", 1) == "A");
    assert(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
}

string convert(string s, int numRows) {
	if (numRows == 1)
		return s;
    string res = "";
    int pos{ 0 }, step{ 0 };
    for (int rowCounter{ 0 }; rowCounter < numRows; rowCounter++) {
        step= 2 * (numRows - 1);
        for (int j{ rowCounter }; j < s.length(); j += step) {
            res += s[j];
            pos = j + step - (rowCounter<<1);
            if (rowCounter > 0 && rowCounter < numRows - 1 && pos < s.length())
                res += s[pos];
        }
    }
    return res;
}