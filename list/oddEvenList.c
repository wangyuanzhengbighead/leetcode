/* 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。 */
/* 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。 */
/* 示例 1: */
/* 输入: 1->2->3->4->5->NULL */
/* 输出: 1->3->5->2->4->NULL */
/* 示例 2: */
/* 输入: 2->1->3->5->6->4->7->NULL  */
/* 输出: 2->3->6->7->1->5->4->NULL */
/* 说明: */
/*     应当保持奇数节点和偶数节点的相对顺序。 */
/*     链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。 */
#include<stdio.h>
#include<stdlib.h>

/* definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head)
{
	if (!head || !head->next || !head->next->next) {
		return head; 
	}
	
	struct ListNode *p, *q, *q1, *tmp;

	p = head;
	q = head->next;
	q1 = head->next;
	while (q && q->next) {
		tmp = q->next;
		q->next = q->next->next;
		p->next = tmp;
		p = p->next;
		q = q->next;
	}

	if (q != NULL) {
		q->next = NULL;
	}
	p->next = q1;

	return head;
}

int main()
{
	struct ListNode *p1, *p2, *p3, *p4, *p5, *p6;

	p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p5 = (struct ListNode*)malloc(sizeof(struct ListNode));

	p1->val = 1;
	p2->val = 2;
	p3->val = 3;
	p4->val = 4;
	p5->val = 5;

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
	
	struct ListNode *p7;

	p7 = oddEvenList(p1);

	while(p7) {
		printf("p7, val: %d\n", p7->val);
		p7 = p7->next;
	}
	
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	
	return 0;
}


       



