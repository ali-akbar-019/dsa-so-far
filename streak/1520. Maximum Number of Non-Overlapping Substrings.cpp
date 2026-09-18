class Solution
{
public:
    vector<string> maxNumOfSubstrings(string s)
    {
        // start //end //result
        vector<int> start(26, -1);
        vector<int> end(26, -1);
        vector<string> result;
        // step 1 start and end mark kar lo
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int idx = s[i] - 'a';
            if (start[idx] == -1)
            {
                start[idx] = i;
            }
            end[idx] = i;
        }
        // step 2: valid invalid sep karo
        vector<bool> isValid(26, true);
        for (int c = 0; c < 26; c++)
        {
            if (start[c] == -1)
                continue;
            for (int i = start[c]; i <= end[c]; i++)
            {
                if (start[s[i] - 'a'] < start[c])
                {
                    isValid[c] = false;
                    break;
                }
                end[c] = max(end[c], end[s[i] - 'a']);
            }
        }
        // step 3
        int lastSelectedStart = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            int idx = s[i] - 'a';
            if (!isValid[idx])
            {
                continue;
            }
            //
            if (start[idx] == i && end[idx] < lastSelectedStart)
            {
                result.push_back(s.substr(i, end[idx] - i + 1));
                lastSelectedStart = i;
            }
        }
        return result;
    }
};