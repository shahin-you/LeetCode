#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

void runTests();
bool isValidSudoku(vector<vector<char>>& board);

int main() {
	runTests();
	return 0;
}

void runTests() {
	vector<vector<char>> b1{ {'.','.','.','.','.','.','.','.','.'},
							 {'.','.','.','.','.','.','.','.','.'},
							 {'.','.','.','.','.','.','.','.','.'},
							 {'.','.','.','.','.','.','.','.','.'},
							 {'.','.','.','.','.','.','.','.','.'},
							 {'.','.','.','.','.','.','.','.','.'},
							 {'.','.','.','.','.','.','.','.','.'},
							 {'.','.','.','.','.','.','.','.','.'},
							 {'.','.','.','.','.','.','.','.','.'} };
	assert(isValidSudoku(b1));
	vector<vector<char>> b2{ {'5','3','.','.','7','.','.','.','.'},
							 {'6','.','.','1','9','5','.','.','.'},
							 {'.','9','8','.','.','.','.','6','.'},
							 {'8','.','.','.','6','.','.','.','3'},
							 {'4','.','.','8','.','3','.','.','1'},
							 {'7','.','.','.','2','.','.','.','6'},
							 {'.','6','.','.','.','.','2','8','.'},
							 {'.','.','.','4','1','9','.','.','5'},
							 {'.','.','.','.','8','.','.','7','9'} };
	assert(isValidSudoku(b2));
	vector<vector<char>> b3{ {'5','.','.','.','.','.','.','.','1'},
							 {'2','.','.','.','.','.','.','.','.'},
							 {'3','.','.','.','.','.','1','.','.'},
							 {'4','.','.','.','.','.','7','.','.'},
							 {'6','.','.','.','.','.','.','.','.'},
							 {'7','.','.','.','.','.','.','.','.'},
							 {'8','.','.','.','.','.','.','.','.'},
							 {'1','.','.','.','.','.','.','.','.'},
							 {'9','.','.','.','.','.','.','.','.'} };
	assert(isValidSudoku(b3)==false);
}

bool isValidSudoku(vector<vector<char>>& board) {
	for (int y{ 0 }; y < 9; y++) {
		for (int x{ 0 }; x < 9; x++) {
			if (board[y][x] == '.')
				continue;
			//check row && col
			for (int index{ 0 };index<9;index++)
				if (index != y && board[index][x] == board[y][x])
					return false;
				else if (index != x && board[y][index] == board[y][x])
					return false;
			//check 3X3
			int newY{ y / 3 }, newX{ x / 3 };
			for (int j{0};j<3;j++)
				for (int i{ 0 }; i < 3; i++) {
					if (board[newY * 3 + j][newX * 3 + i] == board[y][x])
						if (newY * 3 + j != y || newX * 3 + i != x)
							return false;
				}
		}
	}
	return true;
}