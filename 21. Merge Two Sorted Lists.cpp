
/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
Seen this question in a real interview before?
*/




class Solution {
public:
    //合并有序链表
//非递归实现
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *t, *head;
        if(l1->val <= l2->val)
        {
            t = l1;
            l1 = l1->next;
        }
        else
        {
            t = l2;
            l2 = l2->next;
        }

        head = t;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                t->next = l1;
                l1 = l1->next;
            }
            else
            {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }

        if(l1)
        {
            t->next = l1;
        }
        if(l2)
        {
            t->next = l2;
        }

        return head;
    }
};



//递归实现
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    /*递归*/
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    ListNode *p;

    if(l1->val <= l2->val)
    {
        p = l1;
        p->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        p = l2;
        p->next = mergeTwoLists(l1, l2->next);
    }
    return p;
}
