#include "withListNodeDeclare.h"
#include <unordered_map>
#include <iostream>
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
	// 第一次出现的值和指向这个节点的指针
	unordered_map<int, ListNode*> map;
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode* cur = head, *pre = dummyHead;
	while (cur) {
		if (map.find(cur->val) == map.end()) {
			map[cur->val] = pre;
			pre = cur;
			cur = cur->next;
		}
		else {
			while (cur->next && cur->next->val == cur->val) {
				pre = cur;
				cur = cur->next;
			}
			if (cur->next) {
				map[cur->val]->next = cur->next;
				pre = cur;
				cur = cur->next;
			}
			else {
				map[cur->val]->next == nullptr;
				cur = cur->next;
			}
		}
	}
	return dummyHead->next;
}
void traverse(ListNode* head) {
	while (head) {
		cout << head->val << ',';
		head = head->next;
	}
}