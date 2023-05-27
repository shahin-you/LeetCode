#include <iostream>
#include <format>
#include <cassert>
#include <stack>
#include <string>

using namespace std;

void runTests();
bool isValid(string);

int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(isValid("[]") == true);
	assert(isValid("") == true);
	assert(isValid("([])") == true);
	assert(isValid("{[]({})}") == true);
	assert(isValid("{]") == false);
	assert(isValid("({)}") == false);
	assert(isValid("]") == false);
	assert(isValid("(") == false);
}

bool isValid(string s) {
	stack<char> st{};
	for (auto const& c : s) {
		if (c == '(' || c == '{' || c == '[')
			st.push(c);
		else {
			if (st.size() == 0)
				return false;
			if (c == ')') { 
				if (st.top() != '(')
					return false;
				else st.pop();
			}
			if (c == ']') {
				if (st.top() != '[')
					return false;
				else st.pop();
			}
			if (c == '}') {
				if (st.top() != '{')
					return false;
				else st.pop();
			}
		}
	}
	return st.size()==0;

}