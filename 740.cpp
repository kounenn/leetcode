class Solution
{
  public:
    int deleteAndEarn(vector<int> &nums)
    {
        if (!nums.size())
            return 0;
        int max_n = *max_element(begin(nums), end(nums)) + 1;
        if (max_n < 2)
            return 0;
        auto counter = vector<int>(max_n);
        auto dp = counter;
        for (int i : nums)
            counter[i]++;
        dp[1] = counter[1];
        for (int i = 2; i < max_n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + i * counter[i]);
        return dp[max_n - 1];
    }
};