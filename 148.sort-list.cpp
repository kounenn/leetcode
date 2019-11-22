/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (38.11%)
 * Likes:    1890
 * Dislikes: 98
 * Total Accepted:    216.9K
 * Total Submissions: 568.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * Example 1:
 *
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 *
 *
 * Example 2:
 *
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
  void swap(ListNode *n1, ListNode *n2) {
    int temp = n1->val;
    n1->val = n2->val;
    n2->val = temp;
    return;
  }
  void sort(ListNode *begin, ListNode *end) {
    if ((begin == end) || (begin->next == end)) {
      return;
    }
    auto piv = begin->val;
    auto m = begin;
    for (auto cur = begin->next; cur != end; cur = cur->next) {
      if (cur->val < piv) {
        m = m->next;
        swap(m, cur);
      }
    }
    swap(begin, m);
    sort(begin, m);
    sort(m->next, end);
  }

public:
  ListNode *sortList(ListNode *head) {
    sort(head, NULL);
    return head;
  }
};
// @lc code=end
