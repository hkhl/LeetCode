/*
 *Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 *
 *For example, the following two linked lists:
 *
 *A:          a1 → a2
 *                   ↘
 *                     c1 → c2 → c3
 *                   ↗
 *B:     b1 → b2 → b3
 *begin to intersect at node c1.
 *
 *
 *Notes:
 *
 *If the two linked lists have no intersection at all, return null.
 *The linked lists must retain their original structure after the function returns.
 *You may assume there are no cycles anywhere in the entire linked structure.
 *Your code should preferably run in O(n) time and use only O(1) memory.
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //两个链表的交集
    //两个较好的方法：
    //1. 若只是判断链表是否存在香蕉， 不需要找到香蕉的那一点， 则都遍历到最后一个节点看是否相等就ok，因为若香蕉， 最后一定相同
    //   如果需要找到香蕉的节点， 那么需要遍历两个链表的长度， 长度差为n，让长的链表先走n步， 两个链表同时走， 当节点相等时候，香蕉点
    //
    //2. 将其中一条链表首尾链接，  再判断另外一条链表是否存在环， 若存在环， 则香蕉。 环入口， 为香蕉点
    //
    //怎么找到环入口点(两个链表相交点)？        在相遇点设置一个指针， 从表头和相遇点这两个指针同时走， 两指针相遇的点即为环入口点。
    //
    //
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        /*  最简洁的解法
        ListNode *cur1 = headA, *cur2 = headB;
        while (cur1 != cur2)
        {
            cur1 = cur1 ? cur1->next : headB;
            cur2 = cur2 ? cur2->next : headA;
        }
        return cur1;
        */

        //第一种方法
        int len = 0;
        ListNode *other;
        ListNode *bac = headA;
        while (bac)
        {
            len++;
            bac = bac->next;
        }

        bac = headB;
        while (bac)
        {
            len--;
            bac = bac->next;
        }

        if (len > 0)
        {
            bac = headA;
            other = headB;
        }
        else
        {
            bac = headB;
            other = headA;
            len = -len;
        }

        while(len)
        {
            bac = bac->next;
            len--;
        }

        while(bac != other)
        {
            bac = bac->next;
            other = other->next;
        }
        return bac;




        //第二种方法。
        //将链表A变为环  //题目不允许修改链表 - -
      /*
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode *last;
        ListNode *tempA = headA;
        while (tempA->next)
            tempA = tempA->next;
        last = tempA;
        tempA->next = headA;

        ListNode *fast, *slow;
        fast = slow = headB;


        while(fast && fast->next)
        {
            if (fast == slow)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;
        slow = headB;

        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        last->next = NULL;
        return fast;
    */
    }

};
