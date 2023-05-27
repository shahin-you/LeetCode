#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

void runTests();
bool isBipartite(vector<vector<int>>& graph);

int main() {
	runTests();
	return 0;
}

void runTests() {
	vector<vector<int>> test1{ {1,2,3} ,{0,2},{0,1,3},{0,2} };
	assert(isBipartite(test1) == false);

	vector<vector<int>> test2{ {1,3} ,{0,2},{1,3},{0,2} };
	assert(isBipartite(test2));

	vector<vector<int>> test3{ {1} ,{0},{3},{2} };
	assert(isBipartite(test3));

	vector<vector<int>> test4{ {1} ,{0} };
	assert(isBipartite(test4));

	vector<vector<int>> test5{};
	assert(isBipartite(test5));

	vector<vector<int>> test6{ {1,2},{0}, {0},{4},{3} };
	assert(isBipartite(test6));

	//[1,4],[0,2],[1],[4],[0,3]
	vector<vector<int>> test7{ {1,4},{0,2},{1},{4},{0,3} };
	assert(isBipartite(test7));
}

bool isBipartite(vector<vector<int>>& graph) {
	map<int, bool> visited{};
	int color{ 1 }, compColor{ 2 };

	for (int currentRoot{ 0 }; currentRoot < graph.size(); currentRoot++) {
		if (graph[currentRoot].size() == 0 || visited[currentRoot])
			continue;

		queue<int> currentVertices{};
		map<int, int> colorMap{};
		
		currentVertices.push(currentRoot);
		visited[currentRoot] = true;
		colorMap[currentRoot] = color;

		while (!currentVertices.empty()) {
			int currentV = currentVertices.front();
			currentVertices.pop();
			color = colorMap[currentV];
			compColor = color == 1 ? 2 : 1;
			for (const int& v : graph[currentV]) {
				if (visited[v]) {
					if (colorMap[v] == color)
						return false;
					continue;
				}
				else {
					colorMap[v] = compColor;
					visited[v] = true;
					currentVertices.push(v);
				}
			}
		}

	}
	return true;
}