#include <cstdlib>
#include <random>

using namespace std;

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
private:
  ListNode *m_node;

public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
     one node. */
  Solution(ListNode *head) { m_node = head; }

  /** Returns a random node's value. */
  int getRandom() {
    ListNode *res = m_node;
    auto node = m_node->next;
    if (node == NULL) {
      return res->val;
    }

    random_device rd;
    default_random_engine e(rd());
    for (int n = 2; node != NULL; n++, node = node->next) {
      auto dist = uniform_int_distribution<int>(1, n);
      if (dist(e) == 1) {
        res = node;
      }
    }
    return res->val;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */