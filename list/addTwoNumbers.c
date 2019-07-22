/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *p, *cur, *head, *q;
	int carry = 0;
	int x,y;

	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 0;
	head->next = NULL;
	cur = head;

	while (l1 || l2){
		x = l1 ? l1->val : 0;
		y = l2 ? l2->val : 0;

		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;

		p = (struct ListNode *)malloc(sizeof(struct ListNode));
		p->val = (x+y+carry)%10;
		p->next = NULL;

		cur->next = p;
		cur = cur->next;

		carry = (x+y+carry)/10;
	}
	
	if (carry) {
		q = (struct ListNode *)malloc(sizeof(struct ListNode));
		q->val = 1;
		q->next = NULL;

		cur->next = q;
		cur = cur->next;
	}
	
	return head->next;
}

int main()
{
	return  0;
}
