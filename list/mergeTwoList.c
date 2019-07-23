/* 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。  */
/* 示例： */
/* 输入：1->2->4, 1->3->4 */
/* 输出：1->1->2->3->4->4 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode head;
	struct ListNode  *p, *q;

	if (!l1) {
		return l2;
	}

	if (!l2) {
		return l1;
	}

	/* 建立新的头结点 指向L1 */
	head.next = l1;
	l1 = &head;
	
	/* 遍历l2节点 */
	while (l2) {
		p = l1->next;
		q = l2->next;

		if (!l1->next) {
			l1->next = l2;
			break;
		}
		
		if (p->val >= l2->val) {
			l1->next = l2;
			l2->next = p;
			l2 = q;
		}

		l1 = l1->next;
	}
	return head.next;
}

/* for a test */
/* int main() */
/* { */
/* 	struct ListNode *p1, *p2, *p3, *p4; */
/* 	struct ListNode *p5, *p6, *p7; */

/* 	p1 = (struct ListNode *)malloc(sizeof(struct ListNode)); */
/* 	p2 = (struct ListNode *)malloc(sizeof(struct ListNode)); */
/* 	p3 = (struct ListNode *)malloc(sizeof(struct ListNode)); */
/* 	p4 = (struct ListNode *)malloc(sizeof(struct ListNode)); */

/* 	p1->val = 1; */
/* 	p1->next = NULL; */
/* 	p2->val = 2; */
/* 	p2->next = NULL; */
/* 	p3->val = 3; */
/* 	p3->next = NULL; */
/* 	p4->val = 4; */
/* 	p4->next = NULL; */

/* 	p5 = mergeTwoLists(p1, p2); */
/* 	p6 = mergeTwoLists(p3, p4); */
/* 	p7 = mergeTwoLists(p5, p6); */

/* 	while (p7) { */
/* 		printf("list_data: %d \n", p7->val); */
/* 		p7 = p7->next; */
/* 	} */

/* 	free(p1); */
/* 	free(p2); */
/* 	free(p3); */
/* 	free(p4); */

/* 	return 0; */
/* } */
