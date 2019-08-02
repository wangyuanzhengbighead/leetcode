/* 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。 */
/*   */
/* 你可以假设除了数字 0 之外，这两个数字都不会以零开头。 */
/* 进阶: */
/* 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。 */
/* 示例: */
/* 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4) */
/* 输出: 7 -> 8 -> 0 -> 7 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


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

struct ListNode* _addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode head;
	struct ListNode *new;
	int ad_1, ad_2, carry = 0;

	memset(&head, 0, sizeof(struct ListNode));
	l1 = reverseList(l1);
	l2 = reverseList(l2);

	while (l1 || l2) {
		new = (struct ListNode*)malloc(sizeof(struct ListNode));
		memset(new, 0, sizeof(struct ListNode));

		ad_1 = l1 ? l1->val : 0;
		ad_2 = l2 ? l2->val : 0;
	
		new->val = (ad_1 + ad_2 + carry) % 10 ;
		carry = (ad_1 + ad_2 + carry) / 10;

		/* 头插法 */
		new->next = head.next;
		head.next = new;

		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}
	
	if (carry) {
		new = (struct ListNode*)malloc(sizeof(struct ListNode));
		memset(new, 0, sizeof(struct ListNode));

		new->val = 1;
		new->next = head.next;
		head.next = new;
	}

	return head.next;
}
