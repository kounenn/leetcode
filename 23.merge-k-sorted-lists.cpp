/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (36.92%)
 * Likes:    3273
 * Dislikes: 214
 * Total Accepted:    494.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 *
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 *
 *
 */

#include <vector>
using namespace std;

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
  void sift_down(vector<ListNode *> &heap, int p) {
    int s1 = 2 * p + 1;
    while (s1 < heap.size()) {
      int s2 = 2 * p + 2;
      if (s2 < heap.size() && heap[s2]->val < heap[s1]->val) {
        s1 = s2;
      }
      if (heap[p]->val <= heap[s1]->val) {
        break;
      }
      auto temp = heap[p];
      heap[p] = heap[s1];
      heap[s1] = temp;
      p = s1;
    }
  }
  void heapify(vector<ListNode *> &heap) {
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
      sift_down(heap, i);
    }
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<ListNode *> heap;
    heap.reserve(lists.size());
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i] != nullptr) {
        heap.push_back(lists[i]);
      }
    }
    if (heap.size() < 1) {
      return nullptr;
    }
    heapify(heap);
    auto root = heap[0];
    auto cur = root;

    while (heap.size() > 0) {
      if (heap[0]->next != nullptr) {
        heap[0] = heap[0]->next;
      } else {
        heap[0] = heap[heap.size() - 1];
        heap.resize(heap.size() - 1);
      }
      heapify(heap);
      cur->next = heap[0];
      cur = cur->next;
    }
    cur->next = nullptr;
    return root;
  }
};
// @lc code=end
