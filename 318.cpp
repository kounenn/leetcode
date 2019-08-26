class Solution
{
  public:
    int maxProduct(vector<string> &words)
    {
        if (words.size() == 0)
            return 0;
        int max = 0;
        auto s = words.begin();
        auto e = words.end();
        while (s != e - 1)
        {
            for (auto s2 = s + 1; s2 != e; s2++)
            {
                auto c = (*s2).begin();
                auto e = (*s2).end();
                while (c != e)
                {
                    if ((*s).find(*c) != string::npos)
                        break;
                    c++;
                }
                if (c == e)
                {
                    auto t = (*s).length() * (*s2).length();
                    max = t > max ? t : max;
                }
            }
            s++;
        }

        return max;
    }
};