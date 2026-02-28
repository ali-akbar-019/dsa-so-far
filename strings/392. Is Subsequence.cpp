class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        // this approach is better of we have multiple s
        int n = t.size();
        int m = s.size();
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[t[i]].push_back(i);
        }
        // now
        int prev = -1;
        for (int i = 0; i < m; i++)
        {
            char ch = s[i];
            if (mp.find(ch) == mp.end())
            {
                return false;
            }
            // ab check karo kah kaha present ha ye
            vector<int> indices = mp[ch];
            // ab check karo k is character ka index present ha
            auto it = upper_bound(begin(indices), end(indices), prev);
            if (it == indices.end())
            {
                return false;
            }
            // else hame index mil gaya ha
            prev = *it; // prev me value dal do
        }
        return true;
    }
};