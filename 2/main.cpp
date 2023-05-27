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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode* createLList(const vector<int>&);
void deleteLList(ListNode*);
bool isOK(ListNode* head, const vector<int>&);

int main() {
	runTests();
	return 0;
}

void runTests() {
	ListNode* l1 = createLList(vector<int>{1, 2, 3});
	ListNode* l2 = createLList(vector<int>{3, 2, 1});
	assert(isOK(addTwoNumbers(l1, l2), vector<int>{4,4,4}));
	deleteLList(l1);
	deleteLList(l2);

	l1 = createLList(vector<int>{1});
	l2 = createLList(vector<int>{0});
	assert(isOK(addTwoNumbers(l1, l2), vector<int>{1}));
	deleteLList(l1);
	deleteLList(l2);

	l1 = createLList(vector<int>{1});
	l2 = createLList(vector<int>{9});
	assert(isOK(addTwoNumbers(l1, l2), vector<int>{0,1}));
	deleteLList(l1);
	deleteLList(l2);

	l1 = createLList(vector<int>{0});
	l2 = createLList(vector<int>{0});
	assert(isOK(addTwoNumbers(l1, l2), vector<int>{0}));
	deleteLList(l1);
	deleteLList(l2);

	l1 = createLList(vector<int>{9,9,9,9});
	l2 = createLList(vector<int>{1});
	assert(isOK(addTwoNumbers(l1, l2), vector<int>{0,0,0,0,1}));
	deleteLList(l1);
	deleteLList(l2);

	l1 = createLList(vector<int>{2,2});
	l2 = createLList(vector<int>{8,7});
	assert(isOK(addTwoNumbers(l1, l2), vector<int>{0,0,1}));
	deleteLList(l1);
	deleteLList(l2);

	l1 = createLList(vector<int>{0});
	l2 = createLList(vector<int>{0, 9});
	assert(isOK(addTwoNumbers(l1, l2), vector<int>{0, 9}));
	deleteLList(l1);
	deleteLList(l2);
	l1 = createLList(vector<int>{0,1,1});
	l2 = createLList(vector<int>{0, 9});
	assert(isOK(addTwoNumbers(l1, l2), vector<int>{0, 0,2}));
	deleteLList(l1);
	deleteLList(l2);
}

ListNode* createLList(const vector<int>& digits) {
	ListNode* head=nullptr;
	ListNode* current = head;
	for_each(digits.begin(), digits.end(), [&head, &current](const int& d) {
		if (current == nullptr) {
			current = new ListNode(d);
			head = current;
		}
		else {
			current->next = new ListNode(d);
			current = current->next;
		}
	});
	return head;
}


void deleteLList(ListNode* head){
	ListNode* temp = head;
	while (head != nullptr) {
		temp = head->next;
		delete head;
		head = temp;
	}
	head = nullptr;
}

bool isOK(ListNode* head, const vector<int>& v) {
	bool result = true;
	int index = 0;
	while (head != nullptr) {
		if (v[index++] != head->val)
			return false;
		head = head->next;
	}
	return head == nullptr && index == v.size();
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* result{ nullptr }, * current{ nullptr };
	int carry{ 0 }, sum{ 0 };
	while (l1 != nullptr && l2 != nullptr) {
		sum = l1->val + l2->val + carry;
		carry = sum / 10;
		sum %= 10;
		if (current == nullptr) {
			current = new ListNode(sum);
			result = current;
		}
		else {
			current->next = new ListNode(sum);
			current = current->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1 != nullptr) {
		sum = l1->val + carry;
		carry = sum / 10;
		sum %= 10;
		current->next = new ListNode(sum);
		current = current->next;
		l1 = l1->next;
	}
	while (l2 != nullptr) {
		sum = l2->val + carry;
		carry = sum / 10;
		sum %= 10;
		current->next = new ListNode(sum);
		current = current->next;
		l2 = l2->next;
	}
	if (carry!=0)
		current->next = new ListNode(carry);

	return result;
}
