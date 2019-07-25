/* 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。 */
/* k 是一个正整数，它的值小于或等于链表的长度。 */
/* 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 */
/* 示例 : */
/* 给定这个链表：1->2->3->4->5 */
/* 当 k = 2 时，应当返回: 2->1->4->3->5 */
/* 当 k = 3 时，应当返回: 3->2->1->4->5 */

#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n);

/* 从m到n翻转链表 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
	struct ListNode *p, *q;
	struct ListNode HEAD;
	int index, num = m;

	if(num >= n) {
		return head;
	}

	HEAD.next = head;
	head = &HEAD;

	/* 保存第一个前驱节点 */
	while(head && num>1) {
		head = head->next;
		num--;
	}
	p = head->next;

	/* 翻转[m, n]区间链表 */
	index = 0;
	while(index < n-m)
	{
		q = p->next;
		p->next = q->next;
		q->next = head->next;
		head->next = q;
		index++;
	}

	return HEAD.next;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
	struct ListNode new, *p;
	int count, index;
	
	/* 建立新的节点指向原有节点 */
	
	new.next = head;
	head = &new;

	count = 0;
	p = head->next;
	while (p) {
		count++;
		p = p->next;
	}

	index = count/k;
	count = 0;
	while (count<index) {
		head->next = reverseBetween(head->next, count*k+1, (count+1)*k);
		count++;
	}

	return new.next;
}

void main()
{
}
