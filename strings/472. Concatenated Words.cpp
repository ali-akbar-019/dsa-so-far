class Solution
{
public:
    unordered_map<string, bool> mp;
    bool isConcatinated(string &word, unordered_set<string> &st)
    {
        if (mp.find(word) != mp.end())
        {
            return mp[word];
        }
        int l = word.size();

        for (int i = 0; i < l; i++)
        {
            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1);
            if (st.find(prefix) != st.end() && isConcatinated(suffix, st) ||
                (st.find(prefix) != st.end()) && (st.find(suffix) != st.end()))
            {
                return mp[word] = true;
            }
        }
        return mp[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        int n = words.size();
        mp.clear();
        unordered_set<string> st(words.begin(), words.end());
        vector<string> result;
        // set ko use kar rahe ha ta k ham o(1) me check kr sakey
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            if (isConcatinated(word, st))
            {
                result.push_back(word);
            }
        }
        return result;
    }
};