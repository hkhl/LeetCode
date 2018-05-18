/*
 *Given a linked list, determine if it has a cycle in it.
 *
 *Follow up:
 *Can you solve it without using extra space?
 *
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
    //判断链表是否存在在环  快慢指针
    //有环返回rtue 无环返回false
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast && fast->next)
        {
            if(fast == slow)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
