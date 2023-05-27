#include <iostream>
#include <format>
#include <map>

using namespace std;

int romanToInt(string s);

int main() {
	cout << romanToInt("MIC") << endl;
	cout << romanToInt("MXCVIII") << endl;
	cout << romanToInt("MXXII") << endl;
	cout << romanToInt("CIV") << endl;
	cout << romanToInt("V") << endl;
	cout << romanToInt("MMMCCXXI") << endl;
	cout << romanToInt("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDCLIV") << endl;
	return 0;
}

int romanToInt(string roman) {
	static map<char, int> m{ {'I', 1},{'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500},{'M', 1000}};
	if (roman.length() == 0)
		return 0;
	int result{ m.at(roman[roman.length() - 1]) };
	for (int i{ static_cast<int>(roman.length()) - 2 }; i >= 0; i--)
		if (m.at(roman[i]) >= m.at(roman[i + 1]))
			result += m.at(roman[i]);
		else
			result -= m.at(roman[i]);

	return result;
}