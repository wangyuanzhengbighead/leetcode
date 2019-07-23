/* 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。 */
/* 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。 */
/* 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 */
/* 示例： */
/* 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4) */
/* 输出：7 -> 0 -> 8 */
/* 原因：342 + 465 = 807 */

#include<stdio.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

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
