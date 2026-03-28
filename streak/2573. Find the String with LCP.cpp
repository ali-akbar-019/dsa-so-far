class Solution
{
public:
    vector<vector<int>> checkLCP(string &word)
    {
        //
        int n = word.size();
        vector<vector<int>> lcp = vector<vector<int>>(n, vector<int>(n, 0));
        // now we gotta make the lcp vector
        // last col
        for (int i = 0; i < n; i++)
        {
            lcp[i][n - 1] = (word[n - 1] == word[i]) ? 1 : 0;
        }
        // first fill the last row
        for (int i = 0; i < n; i++)
        {
            lcp[n - 1][i] = (word[n - 1] == word[i]) ? 1 : 0;
        }

        // now the rest
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (word[i] == word[j])
                {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                }
                else
                {
                    lcp[i][j] = 0;
                }
            }
        }
        return lcp;
    }
    string findTheString(vector<vector<int>> &lcp)
    {
        int n = lcp.size();
        string word(n, '$');
        // now make the word
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (lcp[i][j] != 0)
                {
                    // then add
                    word[i] = word[j];
                    break;
                }
            }
            //
            if (word[i] == '$')
            {
                // then
                vector<bool> forbidden(26, false);
                for (int j = 0; j < i; j++)
                {
                    if (lcp[j][i] == 0)
                    {
                        forbidden[word[j] - 'a'] = true;
                    }
                }
                //
                for (int idx = 0; idx < 26; idx++)
                {
                    if (forbidden[idx] == false)
                    {
                        word[i] = idx + 'a';
                        break;
                    }
                }
                if (word[i] == '$')
                {
                    return "";
                }
            }
        }
        return checkLCP(word) == lcp ? word : "";
    }
};