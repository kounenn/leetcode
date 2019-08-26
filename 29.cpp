class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        bool s = false;
        if (divisor == 0)
            return INT_MAX;
        if (divisor == 1)
        {
            return dividend;
        }
        if (divisor == -1)
        {
            if (dividend == -INT_MAX - 1)
            {
                return INT_MAX;
            }
            else
            {
                return -dividend;
            }
        }
        s = (dividend < 0) ^ (divisor < 0) ? true : false;
        int res = 0;
        long long d1 = labs(dividend);
        long long d2 = labs(divisor);
        while (d1 >= d2)
        {
            int i = 1;
            long long temp = labs(d2);
            while (temp << 1 <= d1)
            {
                i *= 2;
                temp <<= 1;
            }
            d1 -= temp;
            res += i;
        }
        if (s)
        {
            res = -res;
        }
        return res;
    }
};
