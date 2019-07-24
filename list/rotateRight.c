/* 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。 */

/* 示例 1: */

/* 输入: 1->2->3->4->5->NULL, k = 2 */
/* 输出: 4->5->1->2->3->NULL */
/* 解释: */
/* 向右旋转 1 步: 5->1->2->3->4->NULL */
/* 向右旋转 2 步: 4->5->1->2->3->NULL */
/* 示例 2: */

/* 输入: 0->1->2->NULL, k = 4 */
/* 输出: 2->0->1->NULL */
/* 解释: */
/* 向右旋转 1 步: 2->0->1->NULL */
/* 向右旋转 2 步: 1->2->0->NULL */
/* 向右旋转 3 步: 0->1->2->NULL */
/* 向右旋转 4 步: 2->0->1->NULL */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){

}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
	struct ListNode new;
	struct ListNode *p, *q;
	int index = 0, count = 0;
    
    if (head == NULL || k==0) { 
        return head;
    }

	new.next = head;
	head = &new;

	/* 遍历链表计算数据节点, 并计算节点个数 */
	p = head;
	while (p->next) {
		p = p->next;
		count++;
	}

	k = k%count;
	if (k == 0) {
		return new.next;
	}
	
	/* 构建环形链表 */
	p->next = head->next;
	q = head;
	p = head->next;
	
	while (index < count-k) {
		p = p->next;
		q = q->next;
		index++;
	}

	head->next = p;
    q->next = NULL;

	return new.next;
}
