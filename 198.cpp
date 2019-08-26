class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        int l = nums.size();
        int m = 0;
        int n = 0;
        int temp = 0;
        for (int i = 0; i < l; i++)
        {
            temp = n;
            n = max(n, m + nums[i]);
            m = temp;
        }
        return n;
    }
};