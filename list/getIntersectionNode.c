/* 编写一个程序，找到两个单链表相交的起始节点。 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 节点交叉 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode *p, *q;
	int index = 0;
	p = headA;
	q = headB;

	/* while() */
	while (p) {
		index++;
		p = p->next;
	}

	p = headA;
	q = headB;

	while (q) {
		index++;
		q = q->next;
	}
	
	while (index >= 0) {
		index--;

		/* 偏移之前比较 */
		if (p == q) {
			return p;
		}

		if (p) {
			p = p->next;
		} else {
			p = headB;
		}

		if (q) {
			q = q->next;
		} else {
			q = headA;
		}

	}

	return NULL;
}


///////////////////////////////
////////c++ 简单实现
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        ListNode *q = headB;

        while (p != q) {
            p = ((p==NULL) ? headB :p->next);
            q = ((q==NULL) ? headA :q->next);
        }
        return p;
    }
};
