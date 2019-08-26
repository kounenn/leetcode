class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        auto tails = vector<int>(nums.size());
        int size = 0;
        for (int n : nums) {
            int low = 0;
            int high = size;
            while (low != high) {
                int mid = (low + high) / 2;
                if (tails[mid] < n) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            tails[low] = n;
            if (low == size)
                ++size;
        }
        return size;
    }
};
