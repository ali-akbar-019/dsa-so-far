// approach 1
class Solution
{
public:
    int n;
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s, int &k, int i, int j, vector<vector<int>> &t)
    {
        if (i >= n || j >= n)
        {
            return 0;
        }

        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        //
        // agar to aik palindrome mil gaua current k length ya us se greater me
        if (isPalindrome(s, i, j))
        {
            // rest k recursion le aye ge
            // 3 possibiliies
            //  k aik mil gaya ha ab aage dhondo
            int take = 1 + solve(s, k, j + 1, j + k, t); // j+1  - k length
            int grow = solve(s, k, i, j + 1, t);
            int skip = solve(s, k, i + 1, j + 1, t);
            return t[i][j] = max({take, grow, skip});
        }
        // take to kar nahi sakte
        int grow = solve(s, k, i, j + 1, t);
        int skip = solve(s, k, i + 1, j + 1, t);
        return t[i][j] = max(grow, skip);
    }
    int maxPalindromes(string s, int k)
    {
        n = s.length();
        vector<vector<int>> t(n, vector<int>(n, -1));
        if (k == 1)
        {
            return n;
        }
        return solve(s, k, 0, k - 1, t);
    }
};
