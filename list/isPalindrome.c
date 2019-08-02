/* huiwen */


#include<stdio.h>
#include<stdlib.h>
/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode *p, *q;
	struct ListNode HEAD;
    
    if (!head) {
		return NULL;
	}

	HEAD.next = head;
	head = &HEAD;

	p = head->next;
	while (p->next) {
		q = p->next;
		p->next = q->next;
		q->next = head->next;
		head->next = q;
	}
	
	return HEAD.next;
}


int isPalindrome(struct ListNode* head)
{
	struct ListNode *sl, *fa, new, *mid, *af;
	
	if (!head || !head->next) {
		return 1;
	}
	
	new.next = head;
	head = &new;
	
	sl = head;
	fa = head;

	while (fa && fa->next) {
		sl = sl->next;
		fa = fa->next->next;
	}
	
	mid = sl->next;
	af = reverseList(mid);
	
	struct ListNode *p, *q;
	p = head->next;
	q = af;

	while (q) {
		if (p->val != q->val) {
			return -1;
		}
		p = p->next;
		q = q->next;
	}
	return 1;
}

int main()
{
	struct ListNode *p1, *p2, *p3, *p4, *p5, *p6;

	p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p5 = (struct ListNode*)malloc(sizeof(struct ListNode));

	p1->val = 1;
	p2->val = 2;
	p3->val = 2;
	p4->val = 1;
	p5->val = 0;

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = NULL;
	p5->next = NULL;
	
	int p7;

	p7 = isPalindrome(p1);
	p7 = p7;

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	
	return 0;
}


       



