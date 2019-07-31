#include<stdio.h>
#include<stdlib.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* sort list */
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

struct ListNode* _mergeKLists(struct ListNode** lists, int listsSize)
{
	int count;
	struct ListNode* l1, *l2;
	count = listsSize;

	if (count == 0) {
		return NULL;
	} else if (count == 1) {
		return lists[0];
	} else if (count == 2) {
		return mergeTwoLists(lists[0], lists[1]);
	}
	
	l1 = _mergeKLists(&lists[0], (count+1)/2);
	l2 = _mergeKLists(&lists[(count+1)/2], count - (count+1)/2);
  
	return mergeTwoLists(l1, l2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
	return _mergeKLists(lists, listsSize);
}


struct ListNode* _insertionSortList(struct ListNode* head)
{
	struct ListNode *mid = NULL;
	struct ListNode *s = NULL, *f = NULL;
	struct ListNode *l = NULL, *r = NULL;
	
	s = head;
	f = head;

	if (!head) {
		return NULL;
	} else if (!head->next) {
		return head;
	} else if (!head->next->next) {
		if(head->val > head->next->val) {
			struct ListNode *tmp;
			tmp = head->next;
			head->next = head->next->next;
			tmp->next = head;
			head = tmp;
		}
		return head;
	}

	/* 查询mid链表 */
	while (f && f->next) {
		s = s->next;
		f = f->next->next;
	}
	
	mid = s->next;
	s->next = NULL;

	/* 插入排序两个有序链表 */
	l = _insertionSortList(head);
	r = _insertionSortList(mid);

	return mergeTwoLists(l, r);
}

struct ListNode* insertionSortList(struct ListNode* head)
{
	return _insertionSortList(head);
}

/* int main() */
/* { */
/* 	struct ListNode *p1, *p2, *p3, *p4, *p5, *p6, *pl[5]; */

/* 	p1 = (struct ListNode*)malloc(sizeof(struct ListNode)); */
/* 	p2 = (struct ListNode*)malloc(sizeof(struct ListNode)); */
/* 	p3 = (struct ListNode*)malloc(sizeof(struct ListNode)); */
/* 	p4 = (struct ListNode*)malloc(sizeof(struct ListNode)); */
/* 	p5 = (struct ListNode*)malloc(sizeof(struct ListNode)); */

/* 	p1->val = -1; */
/* 	p2->val = 5; */
/* 	p3->val = 3; */
/* 	p4->val = 4; */
/* 	p5->val = 0; */

/* 	p1->next = NULL; */
/* 	p2->next = NULL; */
/* 	p3->next = NULL; */
/* 	p4->next = NULL; */
/* 	p5->next = NULL; */

/* 	pl[0] = p1; */
/* 	pl[1] = p2; */
/* 	pl[2] = p3; */
/* 	pl[3] = p4; */
/* 	pl[4] = p5; */

/* 	p6 = mergeKLists(pl, ); */

/* 	struct ListNode *p7; */

/* 	p7 = insertionSortList(p6); */
/* 	p7 = p7; */

/* 	free(p1); */
/* 	free(p2); */
/* 	free(p3); */
/* 	free(p4); */
/* 	free(p5); */
	
/* 	return 0; */
/* } */


       
