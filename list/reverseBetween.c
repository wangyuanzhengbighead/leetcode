/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 从m到n翻转链表 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
	struct ListNode *p, *q, *new;
	struct ListNode HEAD;
	int index, num = m;
	
	HEAD.next = head;

	if(num >= n) {
		return head;
	}

	/* 保存第一个前驱节点 */
	new = &HEAD;
	while(new && num>1) {
		new = new->next;
		num--;
	}
	p = new->next;

	/* 翻转[m, n]区间链表 */
	index = 0;
	while(index < n-m)
	{
		q = p->next;
		p->next = q->next;
		q->next = new->next;
		new->next = q;
		index++;
	}

	return HEAD.next;
}

