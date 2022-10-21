#pragma once
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int value):val(value),next(nullptr){}
};
ListNode* deleteDuplicates(ListNode* head);
void traverse(ListNode * head);
