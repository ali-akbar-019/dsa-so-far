class Solution
{
public:
    unordered_set<string> st;
    int n;
    int t[301];
    bool solve(int idx, string &s)
    {
        if (idx == n)
        {
            // means ham torte torte end pe agaye ha ,or sab true ho ge tb hi
            return true;
        }
        //
        if (t[idx] != -1)
        {
            return t[idx];
        }

        // tooro
        for (int l = 1; idx + l <= n; l++)
        {
            // 1 length se n tk tor sakte ha
            string temp = s.substr(idx, l);
            if (st.find(temp) != st.end() && solve(idx + l, s))
            {
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // bar bar word dict se access kare ge to o(n) lage ga
        // isi leye set me dal do ta k o(1) me access kar sake
        for (string &word : wordDict)
        {
            st.insert(word);
        }
        // recursion ko call kar do
        n = s.size();
        memset(t, -1, sizeof(t));
        return solve(0, s);
    }
};