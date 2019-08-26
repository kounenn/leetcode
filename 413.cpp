class Solution
{
  public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        auto size = A.size();
        int sum = 0, cur = 0;
        for (int i = 2; i < size; i++)
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                cur++;
                sum += cur;
            }
            else
            {
                cur = 0;
            }
        }
        return sum;
    }
};