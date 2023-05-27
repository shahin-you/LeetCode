#include <iostream>
#include <format>

#include <map>
#include <vector>
#include <array>
#include <map>
#include <algorithm>

using namespace std;


void runTests();
bool offByOne(string s1, string s2); // it is know that s1 and s2 has the same length
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);

int main() {
	runTests();
	return 0;
}

void runTests() {

}

// it is know that s1 and s2 has the same length
bool offByOne(string s1, string s2) {
	int diffCounter{ 0 };
	for (int i{ 0 }; diffCounter < 2 && i < s1.length(); i++) 
		if (s1[i] != s2[i])
			diffCounter++;
	return diffCounter == 1;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
		return vector<vector<string>>{};
	wordList.insert(wordList.begin(), beginWord);
	//vector<pair<string, string>> graph{};
	map<string, string> edges{};
	//build graph
	bool startHasEdgeOut{ false }, endHasEdgeIn{ false };
	for (int i{ 0 }; i < wordList.size(); i++)
		for (int j{ 0 }; i < wordList.size(); j++)
			if (offByOne(wordList[i], wordList[j])) {
				startHasEdgeOut = i == 0;
				endHasEdgeIn = j == wordList.size();
				//graph.push_back(make_pair(wordList[i], wordList[j]));
				edges[wordList[i]] = wordList[j];
			}
	if (!startHasEdgeOut || !endHasEdgeIn)
		return vector<vector<string>> {};

	//okay lets find the shortest paths,

}

