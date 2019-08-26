class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int step = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] < step)
            {
                ++step;
            }
            else
            {
                step = 1;
            }
        }
        return step == 1;
    }
};