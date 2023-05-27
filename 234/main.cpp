#include <iostream>
#include <format>


#include <cassert>
#include <string>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head);
bool isPalindrome2(ListNode* head);
ListNode* createListFor(const string& s);
void deleteList(ListNode* head);
void runTests();

int main() {
	runTests();
	return 0;
}

void runTests() {
	ListNode* test;

	test = createListFor("110050011");
	assert(isPalindrome2(test));
	deleteList(test);
	test = createListFor("9");
	assert(isPalindrome2(test));
	deleteList(test);
	test = createListFor("77");
	assert(isPalindrome2(test));
	deleteList(test);
	test = createListFor("858");
	assert(isPalindrome2(test));
	deleteList(test);
	test = createListFor("666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666");
	assert(isPalindrome2(test));
	deleteList(test);
	test = createListFor("1234567890987654312");
	assert(isPalindrome2(test) == false);
	deleteList(test);
	test = createListFor("123");
	assert(isPalindrome2(test) == false);
	deleteList(test);
	test = createListFor("456548");
	assert(isPalindrome2(test) == false);
	deleteList(test);

}

ListNode* createListFor(const string& s) {
	if (s.empty()) return nullptr;
	ListNode* head = nullptr, *currentPointer=nullptr;
	for (const char& c : s) {
		ListNode* newNode = new ListNode(c-'0');
		if (head == nullptr)
			head = newNode;
		else
			currentPointer->next = newNode;
		currentPointer = newNode;
	}
	return head;
}

void deleteList(ListNode* head) {
	while (head != nullptr) {
		ListNode* next = head->next;
		delete head;
		head = next;
	}
}

bool isPalindrome(ListNode* head) {
	if (head->next == nullptr)
		return true;

	ListNode* p = head->next;
	stack<int> s{};
	int listLength = 1;
	while (p != nullptr) {
		listLength++;
		p = p->next;
	}
	p = head;
	for (int i{ 0 }; i < listLength / 2; i++, p = p->next)
		s.push(p->val);

	if (listLength % 2 == 1)
		p = p->next;

	for (int i{ 0 }; i < listLength / 2; i++, p = p->next, s.pop())
		if (s.top() != p->val)
			return false;
	return true;
}

bool isPalindrome2(ListNode* head) {
	if (head->next == nullptr)
		return true;
	ListNode* fast = head, *prev=nullptr, *curr=head, *temp=nullptr;
	while (fast && fast->next) {
		fast = fast->next->next;
		//reverse slow
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	ListNode* right = fast ? curr->next : curr;
	ListNode* left = prev;
	while (right && left) {
		if (right->val != left->val)
			return false;
		right = right->next;
		left = left->next;
	}
	return true;

}