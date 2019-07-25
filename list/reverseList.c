/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head);

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
