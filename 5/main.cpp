#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <string>
using namespace std;

void runTests();
string longestPalindrome(string s);

bool memo[1000][1000]{ false };

int main() {
	runTests();
	return 0;
}

void runTests() {
	assert(longestPalindrome("a") == "a");

	assert(longestPalindrome("aa") == "aa");
	assert(longestPalindrome("ab") == "a");

	assert(longestPalindrome("abc") == "a");
	assert(longestPalindrome("abb") == "bb");
	assert(longestPalindrome("aab") == "aa");
	assert(longestPalindrome("kkk") == "kkk");
	assert(longestPalindrome("k1k") == "k1k");

	assert(longestPalindrome("ak1kd") == "k1k");
	assert(longestPalindrome("ddk1kz") == "k1k");
	assert(longestPalindrome("ddk1kzddk1kzddk1kz") == "k1k");
	assert(longestPalindrome("ddk1kzddk1kzd22122") == "22122");
	assert(longestPalindrome("abcddcba") == "abcddcba");
	assert(longestPalindrome("1abcddcba") == "abcddcba");
	assert(longestPalindrome("abcddcba1") == "abcddcba");

	assert(longestPalindrome("zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir") == "gykrkyg");
}

string longestPalindrome(string s) {
	int strLen = s.size();
	if (strLen == 1)
		return s;
	memset(memo, 0, sizeof(bool) * 1000000);
	int i{ 0 };
	int maxStart{ 0 }, maxEnd{ 0 };
	for (; i < strLen; i++) 
		memo[i][i] = true;
	for (int l = 2; l <= strLen; l++) {
		for (i = 0; i <= strLen - l; i++) {
			int j = i + l - 1;
			if (s[i] == s[j] && (l == 2 || memo[i + 1][j - 1])) {
					memo[i][j] = true;
					if (l > maxEnd - maxStart) {
						maxStart = i;
						maxEnd = j;
					}
				}
			}
	}
	return s.substr(maxStart, maxEnd - maxStart+1);
}