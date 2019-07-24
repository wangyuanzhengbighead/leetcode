/* 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。 */
/* 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 */
/* 示例: */
/* 给定 1->2->3->4, 你应该返回 2->1->4->3. */
/* 来源：力扣（LeetCode） */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head)
{
	struct ListNode new;
	struct ListNode *p, *q, *tmp;

	if (!head) {
		return NULL;
	}

	/* 添加头结点 */
	new.next = head;
	head = &new;
	p = head;

	while (p->next->next != NULL) {
		/* 保存指向P的节点 */
		tmp = p;
		p = p->next;   
		q = p->next;

		/* P和q交换位置 */
		p->next = q->next;
		q->next = p;
		tmp->next = q;

        if (!(p->next)) {
            break;
        }
    
	}

	return head->next;
}
