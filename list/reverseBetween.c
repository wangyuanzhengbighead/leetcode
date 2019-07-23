/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 从m到n翻转链表 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
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

