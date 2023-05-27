#include <iostream>
#include <format>

#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void runTests();
ListNode* swapPairs(ListNode* head);

ListNode* makeLListFromVector(const vector<int>&);
void deleteLList(ListNode *);
bool theSame(ListNode*, const vector<int>&);

int main() {
	runTests();
	return 0;
}

void runTests() {
	ListNode* testData = makeLListFromVector(vector<int>{1, 2, 3, 4});
	assert(theSame(swapPairs(testData), vector<int>{2,1,4,3}));
	deleteLList(testData);
	testData = makeLListFromVector(vector<int>{1, 2});
	assert(theSame(swapPairs(testData), vector<int>{2, 1}));
	deleteLList(testData);

	testData = makeLListFromVector(vector<int>{});
	assert(theSame(swapPairs(testData), vector<int>{}));
	deleteLList(testData);
	testData = makeLListFromVector(vector<int>{2});
	assert(theSame(swapPairs(testData), vector<int>{2}));
	deleteLList(testData);

	testData = makeLListFromVector(vector<int>{1, 2 ,3});
	assert(theSame(swapPairs(testData), vector<int>{2, 1, 3}));
	deleteLList(testData);
	testData = makeLListFromVector(vector<int>{1, 2, 3, 4, 5});
	assert(theSame(swapPairs(testData), vector<int>{2, 1, 4, 3, 5}));
	deleteLList(testData);

}

ListNode* makeLListFromVector(const vector<int>& values) {
	ListNode* head = nullptr;
	ListNode* current = head, *prev=nullptr;
	for (const int v : values) {
		current = new ListNode(v);
		if (head == nullptr)
			head = current;
		if (prev != nullptr)
			prev->next = current;
		prev = current;
	}
	return head;
}

void deleteLList(ListNode* head) {
	ListNode* temp = head;
	while (head != nullptr) {
		temp = head->next;
		delete head;
		head = temp;
	}
}

bool theSame(ListNode* l, const vector<int>& v) {
	bool result = false;
	int index = 0;
	while (l != nullptr && index<v.size()) {
		if (l->val != v[index++])
			return false;
		l = l->next;
	}
	return l==nullptr && index==v.size();
}

ListNode* swapPairs(ListNode* head) {
	if (head == nullptr)
		return head;
	ListNode* next{ head->next }, * curr{ head }, * lastCurrent{ nullptr };
	while (next != nullptr) {
		curr->next = next->next;
		next->next = curr;
		if (lastCurrent == nullptr)
			head = next;
		else
			lastCurrent->next = next;

		lastCurrent = curr;
		curr = curr->next;
		if (curr == nullptr)
			break;
		next = curr->next;
	}
	return head;
}