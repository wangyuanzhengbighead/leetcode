/* 给定一个单链表 L：L0→L1→…→Ln-1→Ln ， */
/* 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→… */
/* 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 */
/* 示例 1: */
/* 给定链表 1->2->3->4, 重新排列为 1->4->2->3. */
/* 示例 2: */
/* 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3. */
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

void reorderList(struct ListNode* head)
{
	struct  ListNode *s, *f, *r, new;
	struct  ListNode *p, *q;

	if ((!head) || (!head->next) || (!head->next->next)) {
		return head;
	}

	new.next = head;
	head = &new;
	s = head;
	f = head;

	/* 双指针找到分割点 */
	while (f && f->next) {
		s = s->next;
		f = f->next->next;
	}

	/* 分割链表 */
	p = head->next;
	q = s->next;
	s->next = NULL;

	/* 逆序2 */
	q = reverseList(q);

	while (q) {
		r = q->next;
		q->next = p->next;
		p->next = q;

		p = q->next;
		q = r;
	}

	return head;
}
