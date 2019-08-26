class Solution
{
  public:
    bool isSubsequence(string s, string t)
    {
        string::size_type pos = 0;
        for (auto c = s.begin(); c != s.end(); c++)
        {
            pos = t.find_first_of(*c, pos);
            if (pos == t.npos)
            {
                return false;
            }
            else
            {
                pos++;
            }
        }
        return true;
    }
};