/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 移除链表所有此元素的值 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (!head) {
		return head;
	}

	struct ListNode *p, *tmp, new;

	new.next = head;
	head = &new;
	
	p = head;
	while (p->next) {
		if (p->next->val == val) {
			tmp = p->next;
			p->next = p->next->next;
			p = tmp;
			continue;
		}
		p = p->next;
	}
	
	return new.next;
}

