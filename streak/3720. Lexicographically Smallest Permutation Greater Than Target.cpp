class Solution
{
public:
    string result;
    bool solve(int i, string curr, string target, vector<int> &count, bool greater)
    {
        if (i == target.size())
        {
            if (greater)
            {
                result = curr;
                return true;
            }
            else
            {
                return false;
            }
        }
        // ab try karo characters
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (count[ch - 'a'] <= 0)
                continue;
            if (greater == false && ch < target[i])
                continue;

            // try karte ha
            curr.push_back(ch);
            count[ch - 'a']--;
            bool isGreater = greater || ch > target[i];
            if (solve(i + 1, curr, target, count, isGreater))
            {
                return true;
            }
            curr.pop_back();
            count[ch - 'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target)
    {
        vector<int> count(26, 0);
        for (auto &ch : s)
        {
            count[ch - 'a']++;
        }
        string curr;
        solve(0, curr, target, count, false);
        return result;
    }
};