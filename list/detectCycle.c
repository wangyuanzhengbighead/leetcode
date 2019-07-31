/* 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。 */
/* 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。 */
/* 说明：不允许修改给定的链表。 */
/* Definition for singly-linked list. */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *_intersect(struct ListNode *head)
{
	struct ListNode *sl, *fa;

	if (!head) {
		return NULL;
	}

	sl = head;
	fa = head;

	int index1 = 0;
	while (fa && fa->next) {
		index1++;
		
		sl = sl->next;
		fa = fa->next->next;
		if (sl == fa) {
			return sl;
		}
	}
	
	return NULL;
}

struct ListNode *detectCycle(struct ListNode *head)
{
	struct ListNode *p1, *p2;
	struct ListNode *intersect;

	intersect = _intersect(head);
	if (!intersect) {
		return NULL;
	}

	p1 = head;
	p2 = intersect;

	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
