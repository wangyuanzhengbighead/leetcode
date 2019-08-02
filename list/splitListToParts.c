/* 给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。 */
/* 每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。 */
/* 这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。 */
/* 返回一个符合上述规则的链表的列表。 */
/* 举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ] */
/* 示例 1： */
/* 输入:  */
/* root = [1, 2, 3], k = 5 */
/* 输出: [[1],[2],[3],[],[]] */
/* 解释: */
/* 输入输出各部分都应该是链表，而不是数组。 */
/* 例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且 root.next.next.next = null。 */
/* 第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。 */
/* 最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize)
{
	struct ListNode **nw;
	struct ListNode *p, *tmp;

	int size = 0;
	int index = 0;

	nw = (struct ListNode**)malloc((sizeof(struct ListNode *) * k));
    for(index=0; index<k; index++) {
		nw[index] = NULL;
	}
	/* count = index; */
	/* 计算链表长度 */
	p = root;
	while (p) {
		p = p->next;
		size++;
	}

	*returnSize = k;
	p = root;
	if (k > size) {
		for (index = 0; index < k; index++) {
			if (index >= size) {
				nw[index] = NULL;
			} else {
				tmp = p->next;
				p->next = NULL;
				nw[index] = p;
				p = tmp;
			}
		}
		return nw;
	}

	int a = size % k;
	int b = size / k;
	int count;

	/* (0, a) b+1---- [a,b) b */
	/*  */
	p = root;
	for(index = 0; index < k; index++) {
		nw[index] = p;

		if (a > 0) {
			for(count = 0; count < b; count++) {
				p = p->next;
			}
		} else {
			for(count = 0; count < b-1; count++) {
				p = p->next;
			}
		}

		a--;
		tmp = p->next;
		p->next = NULL;
		p = tmp;
	}
	return nw;
}
