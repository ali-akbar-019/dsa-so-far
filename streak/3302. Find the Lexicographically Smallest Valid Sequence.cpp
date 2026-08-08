class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        // greedy
        int n = word1.size();
        int m = word2.size();

        // last index wali array bana lo
        vector<int> last(m, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (word1[i] == word2[j])
            {
                last[j] = i;
                j -= 1;
                if (j < 0)
                    break;
            }
        }
        // we can change one time
        bool change = false;
        j = 0;
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (word1[i] == word2[j])
            {
                result.push_back(i);
                j++;
            }
            else if ((!change && j == m - 1) || (!change && last[j + 1] > i))
            {
                change = true;
                result.push_back(i);
                j++;
            }
            if (j >= m)
                break;
        }
        if (result.size() != m)
        {
            return {};
        }
        return result;
    }
};