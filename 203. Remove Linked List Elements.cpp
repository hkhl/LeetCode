/*
 *Remove all elements from a linked list of integers that have value val.
 *
 *Example:
 *
 *Input:  1->2->6->3->4->5->6, val = 6
 *Output: 1->2->3->4->5
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
    //删除链表中的val元素
    ListNode* removeElements(ListNode* head, int val)
    {
        /* 两个指针 首尾指针删除
        if (head == NULL)
            return NULL;

        ListNode *cur = head;
        ListNode *pre = head;
        ListNode *del = NULL;
        while (cur)
        {
            if (cur->val == val)
            {
                if (cur == head)
                {
                    //del = head;
                    head = head->next;
                    //delete del;
                }
                else
                {
                    //del = cur;
                    pre->next = cur->next;
                    //delete del;
                }
            }
            else
                pre = cur;
            cur = cur->next;

        }
        return head;
    */



        //递归实现
        //ListNode* removeElements(ListNode* head, int val)

        //假设有两个元素  1 2  现在删除1
        if (head == NULL)
            return head;
        head->next = removeElements(head->next, val);  //后面链表的处理结果交给head->next

        return head->val == val ?  head->next : head;
    }

};
