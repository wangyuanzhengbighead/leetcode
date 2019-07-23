/* 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。 */
/* 示例： */
/* 给定一个链表: 1->2->3->4->5, 和 n = 2. */
/* 当删除了倒数第二个节点后，链表变为 1->2->3->5. */
/* 说明： */
/* 给定的 n 保证是有效的。 */
/* 进阶： */
/* 你能尝试使用一趟扫描实现吗？ */
/* 来源：力扣（LeetCode） */

#include<stdio.h>
#include<stdlib.h>
/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	struct ListNode new;
	struct ListNode *p;
	int count = 0, real_count = 0;
	
	new.next = head;
	head = &new;

	p = head->next;
	while (p) {
		count++;
		p = p->next;
	}

	real_count = count - n + 1;

	while (real_count > 1) {
		real_count --;
		head = head->next;
	}

	p = head->next;
	head->next = head->next->next;
	free(p);

	return new.next;
}

int main()
{
	return 0;
}
