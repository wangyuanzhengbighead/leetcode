/* 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。 */
/* 你应当保留两个分区中每个节点的初始相对位置。 */
/* 示例: */
/* 输入: head = 1->4->3->2->5->2, x = 3 */
/* 输出: 1->2->2->4->3->5 */

/* Definition for singly-linked list. */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x)
{
	struct ListNode new,new2;
	struct ListNode *be, *af, *crr;

	if (!head) return head;
	
	/* 创建新链表的头节点 */
	be = (struct ListNode *)malloc(sizeof(struct  ListNode));
	af = (struct ListNode *)malloc(sizeof(struct  ListNode));

	be->next = NULL;
	af->next = NULL;

	new.next = be;
	new2.next = af;
	
	crr = head;
	while (crr) {
		if (crr->val < x) {
			be->next = crr;
			be = crr;
		} else {
			af->next = crr;
			af = crr;
		}
		crr = crr->next;
	}
	be->next = new2.next;
	af->next = NULL;

	return new.next->next;
}

