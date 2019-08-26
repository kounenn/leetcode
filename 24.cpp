#include "header.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *cur, *pre;
        int temp = 0;
        bool flag = true;
        cur = pre = head;
        while (cur->next)
        {
            cur = cur->next;
            if (flag)
            {
                temp = pre->val;
                pre->val = cur->val;
                cur->val = temp;
            }
            pre = cur;
            flag = !flag;
        }
        return head;
    }
};