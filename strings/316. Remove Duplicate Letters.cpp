// 1081. Smallest Subsequence of Distinct Characters
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int n = s.length();
        // visit kar leya ?
        // last index kya ha
        vector<bool> visit(26, 0);
        vector<int> lastIndex(26);
        // first get all the last idexes
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            int idx = ch - 'a';
            lastIndex[idx] = i;
        }
        // now check
        string result;
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            int idx = ch - 'a';
            if (visit[idx])
                continue;
            while (!result.empty() && result.back() > ch && lastIndex[result.back() - 'a'] > i)
            {
                visit[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            visit[idx] = true;
        }
        return result;
    }
};