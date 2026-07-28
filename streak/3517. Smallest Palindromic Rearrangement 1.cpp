// wrong code
class Solution
{
public:
    string smallestPalindrome(string s)
    {
        unordered_map<char, int> mp;
        for (auto &ch : s)
        {
            mp[ch]++;
        }
        //
        string result = "";
        for (int i = 'a'; i <= 'z'; i++)
        {
            //
            if (!mp.count(i))
                continue;
            // ab hame mid pe insert karna ha
            int mid = result.length() / 2;
            if (mid != 0)
                result.insert(mid, mp[i], i);
            else
                result.insert(0, mp[i], i);
        }
        return result;
    }
};
// correct code
class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int n = s.length();
        int m = n / 2;
        sort(begin(s), begin(s) + m);
        // ab mirror image
        for (int i = 0; i < n; i++)
        {
            s[n - 1 - i] = s[i];
        }
        return s;
    }
};