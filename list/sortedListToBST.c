/* 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。 */

/* 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。 */

/* 示例: */

/* 给定的有序链表： [-10, -3, 0, 5, 9], */

/* 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树： */

/*       0 */
/*      / \ */
/*    -3   9 */
/*    /   / */
/*  -10  5 */

/* Definition for singly-linked list. */
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* Definition for a binary tree node.XS */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
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


struct ListNode* findmiddlepoint(struct ListNode* head)
{
	struct ListNode *p1, *p2, *pre;
	/* 双指针 */
	p1 = head;
	p2 = head;
	pre = NULL;
	
	/* new.next = head; */
	/* head = &new; */
	while ((p2) && (p2->next)) {
		pre = p1;
		p1 = p1->next;
		p2 = p2->next->next;
	}

	if (pre) {
		pre->next = NULL;
	}

	return p1;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
	struct ListNode *m;
	struct TreeNode *mid;

	if (!head) {
		return NULL;
	}
	
	m = findmiddlepoint(head);
	mid = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	memset(mid, 0, sizeof(struct TreeNode));
	mid->val = m->val;

	if (m == head) {
		return mid;
	}

	mid->left = sortedListToBST(head);
	mid->right = sortedListToBST(m->next);

	return mid;
}

/* for a test */
int main()
{
	struct ListNode *p1, *p2, *p3, *p4, *p5, *l1;
	struct ListNode *pl[5];
	struct TreeNode *l2;
	
	p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p4 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p5 = (struct ListNode *)malloc(sizeof(struct ListNode));

	p1->val = -10;
	p2->val = -3;
	p3->val = -0;
	p4->val = 5;
	p5->val = 9;

	p1->next = NULL;
	p2->next = NULL;
	p3->next = NULL;
	p4->next = NULL;
	p5->next = NULL;

	pl[0] = p1;
	pl[1] = p2;
	pl[2] = p3;
	pl[3] = p4;
	pl[4] = p5;

	l1 = mergeKLists(pl, 5);
	l2 = sortedListToBST(l1);

	/* while(l2){ */
	/* 	printf() */
	/* } */
	
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	
	return 0;
}
