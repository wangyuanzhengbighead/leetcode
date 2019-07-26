/* 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。 */
/* 示例 1: */
/* 输入: 1->2->3->3->4->4->5 */
/* 输出: 1->2->5 */
/* 示例 2: */
/* 输入: 1->1->1->2->3 */
/* 输出: 2->3 */

/* Definition for singly-linked list. */


#include<stdio.h>
#include<stdlib.h>

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode new;
	struct ListNode *p, *q, *tmp;

	if (!head) {
		return head;
	}
	new.next = head;
	head = &new;

	p = head->next;

	/* find head list */
	while (p) {
		q = p->next;
		if (q == NULL || p->val != q->val) {
			head->next = p;
			break;
		} 

		while (q && (p->val == q->val)) {
			/* p = p->next; */
			q = q->next;
		}
  
		if (!q) {
			return NULL;
		}
		p = q;
	}

	tmp = p;
	while (p) {
		q = p->next;
		if (q == NULL) {
			/* quit */
			if (tmp != p) {
				tmp->next = p;
			}
			break;
		}

		if (p->val != q->val) {
			/* end */
			if (q->next == NULL) {
				if (tmp != p) {
					tmp->next = p;
				}
				break;
			} else {
				while (p->val != q->val) {

					 if (tmp != p){
						tmp->next = p;
						tmp = p;
					}
						
					p = p->next;
					q = q->next;
					if (!q) {
						tmp->next = p;
						tmp = p;
						break;
					}
				}
			}
		}

		while (q && p->val == q->val) {
			q = q->next;
		}
		
		if (q == NULL) {
			tmp->next = NULL;
		}
		
		p = q;
	}
 
	return new.next;
}

