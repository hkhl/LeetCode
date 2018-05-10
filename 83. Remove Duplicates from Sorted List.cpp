/*
 *
 *Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 *Example 1:
 *
 *Input: 1->1->2
 *Output: 1->2
 *Example 2:
 *
 *Input: 1->1->2->3->3
 *Output: 1->2->3
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
    //删除链表重复元素
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *bac = head;
        if(head == NULL || head->next == NULL)
            return head;
        while (head->next)
        {
            if (head->next && head->next->val == head->val)
            {
                //删除节点
                //ListNode* temp = head->next;
                head->next = head->next->next;
                //delete temp;
            }
            else
                head = head->next;
        }
        return bac;
    }
};
