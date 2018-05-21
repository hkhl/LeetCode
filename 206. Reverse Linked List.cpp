/*
 *Reverse a singly linked list.
 *
 *Example:
 *
 *Input: 1->2->3->4->5->NULL
 *Output: 5->4->3->2->1->NULL
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
    //链表翻转
    ListNode* reverseList(ListNode* head)
    {
        //非递归

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *left = head;
        ListNode *cur = head->next;
        ListNode *right = cur->next;

        /*
        while (right)
        {
            cur->next = left;
            left = cur;
            cur = right;
            right = right->next;
        }
        head->next = NULL;
        cur->next = left;
        return cur;
        */

        //  or

        while (cur)
        {
            right = cur->next;
            cur->next = left;

            left = cur;
            cur = right;
        }
        head->next = NULL;
        return left;


        //递归
        /*
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *Node = reverseList(head->next);
        head->next->next = head->next;
        head->next = NULL;
        return Node;
        */
    }
};
