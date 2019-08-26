#include "header.h"
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        auto head = nums.begin();
        auto cur = head;
        auto end = nums.end();
        auto tail = end - 1;
        while (cur < tail) {
            if (cur < tail && *cur == 2) {
                std::swap(*cur, *tail);
                --tail;
            } else if (cur > head && *cur == 0) {
                std::swap(*cur, *head);
                ++head;
            } else {
                ++cur;
            }
        }
    }
};
