class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        auto size = nums.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return nums[0];
        return max(subRob(nums, 0, size - 2), subRob(nums, 1, size - 1));
    }

  private:
    int subRob(vector<int> &nums, int m, int n)
    {
        int pre, next, temp;
        pre = next = 0;
        for (int i = m; i <= n; i++)
        {
            temp = next;
            next = max(next, nums[i] + pre);
            pre = temp;
        }
        return next;
    }
};