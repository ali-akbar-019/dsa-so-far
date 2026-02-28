class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k > 1)
        {
            sort(begin(s), end(s));
            return s;
        }
        //
        int n = s.size();
        string ans = s;
        for (int i = 0; i <= n - 1; i++)
        {
            string temp = s.substr(i) + s.substr(0, i);
            ans = min(ans, temp);
        }
        return ans;
    }
};