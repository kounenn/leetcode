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
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }
        ListNode *cur = head;
        ListNode *pre = cur;
        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                pre->next = cur->next;
            }
            else
            {
                pre = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};
