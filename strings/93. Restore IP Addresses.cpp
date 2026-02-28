class Solution
{
public:
    vector<string> result;
    int n;
    bool isValid(string curr)
    {
        if (curr.size() > 1 && curr[0] == '0')
        {
            return false;
        }
        //
        int val = stoi(curr);
        return val <= 255;
    }
    void solve(string &s, int parts, string curr, int idx)
    {
        if (parts > 4)
        {
            return;
        }
        if (idx == n && parts == 4)
        {
            // pehle to wo ahir wala dot remove kar do
            curr.pop_back();
            result.push_back(curr);
            return;
        }
        //
        // ab aik lo
        if (idx + 1 <= n)
        {
            solve(s, parts + 1, curr + s.substr(idx, 1) + ".", idx + 1);
        }
        // do le lo
        if (idx + 2 <= n && isValid(s.substr(idx, 2)))
        {
            solve(s, parts + 1, curr + s.substr(idx, 2) + ".", idx + 2);
        }
        // three le lo
        if (idx + 3 <= n && isValid(s.substr(idx, 3)))
        {
            solve(s, parts + 1, curr + s.substr(idx, 3) + ".", idx + 3);
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        n = s.size();
        result.clear();
        if (n > 12)
        {
            return {};
        }
        int parts = 0;
        string curr = "";
        solve(s, parts, curr, 0);
        return result;
    }
};