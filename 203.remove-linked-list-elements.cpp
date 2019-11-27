/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (36.67%)
 * Likes:    1058
 * Dislikes: 60
 * Total Accepted:    264.4K
 * Total Submissions: 720.1K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example:
 *
 *
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *cur = head, *pre = nullptr, *new_head = head;
    for (; cur != nullptr; cur = cur->next) {
      if (cur->val == val) {
        if (pre != nullptr) {
          pre->next = cur->next;
        } else {
          new_head = cur->next;
        }
        continue;
      }
      pre = cur;
    }
    return new_head;
  }
};
// @lc code=end
