/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (47.09%)
 * Likes:    1523
 * Dislikes: 137
 * Total Accepted:    377K
 * Total Submissions: 799.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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

class Solution {
private:
  ListNode *swap(ListNode *n) {
    auto root = n->next;
    n->next = n->next->next;
    root->next = n;
    return root;
  }

public:
  ListNode *swapPairs(ListNode *head) {
    ListNode root(0);
    root.next = head;
    auto cur = &root;
    for (int i = 1; cur->next != nullptr && cur->next->next != nullptr; i++) {
      if (i % 2 != 0) {
        cur->next = swap(cur->next);
      }
      cur = cur->next;
    }
    return root.next;
  }
};
// @lc code=end
