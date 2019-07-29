/* 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。 */
/* 示例 1: */
/* 输入: 1->1->2 */
/* 输出: 1->2 */
/* 示例 2: */
/* 输入: 1->1->2->3->3 */
/* 输出: 1->2->3 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode new;
	struct ListNode *p, *q;

	if (!head) {
		return head;
	}

	new.next = head;
	head = &new;
	p = head->next;
	
	/* p = head->next; */
    while (p && p->next)
	{
		q = p->next;

		/* while (q && (p->val == q->val)) { */
		/* 	q = q->next; */
		/* 	p->next = q; */
		/* } */

		/* p = p->next; */
		/* if (!q) { */
		/* 	break; */
		/* } */

		if (p->val == q->val) {
			p->next = q->next;
		} else {
			p = p->next;
		}
	}

	return new.next;
}
