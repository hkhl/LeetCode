/*
 *Given a singly linked list, determine if it is a palindrome.
 *
 *Example 1:
 *
 *Input: 1->2
 *Output: false
 *Example 2:
 *
 *Input: 1->2->2->1
 *Output: true
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
    //确定链表是否回文
    //1->2->1
    //拼接字符串
    //链表翻转
    //栈
    //递归

  /*  不反转链表的话，可以使用递归，利用函数的调用栈来实现链表数据的逆向保存，大致的思路是这样的，左右节点两个指针，递归调用中判断1. 子链表是否回文(除右节点的子链表，递归调用)2. 当前的左右节点是否相同只要一个不满足，即不是回文，最后当右节移动到了链表尾部，全部满足，说明链表回文，时间复杂度和空间复杂度(不考虑递归的空间消耗)同上，简单的代码
*/
    bool isPalindrome(ListNode* head)
    {
        int lhash = 0, rhash = 0;
        for(int x = 1; head != NULL; head = head->next, x *= 31) {
            lhash = lhash*31 + head->val;        //相当于，           31^(n-1)*s[0] +  31^(n-2)*s[1] + ... + s[n-1]
            rhash = rhash + head->val*x;         //上述过上逆运算， 因为s[n-1] == s[0] 链表对称
                                                 //                  s[0] + 31^1*s[1] + 31^2*[s2] + ... + 31^(n-1)*s[n-1]
                                                 //                  如果相等，则说明链表是逆序的
        }
        return lhash == rhash;

        //上述方法是JAVA中  string的 hashCode实现方法

    }

};
