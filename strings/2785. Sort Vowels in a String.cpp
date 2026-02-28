class Solution
{
public:
    bool isVowel(char ch)
    {
        char lCh = tolower(ch);
        if (lCh == 'a' || lCh == 'e' || lCh == 'i' || lCh == 'o' || lCh == 'u')
        {
            return true;
        }
        return false;
    }
    string sortVowels(string s)
    {
        vector<char> v;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]))
            {
                v.push_back(s[i]);
            }
        }
        // sort kar do
        sort(v.begin(), v.end());
        //
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]))
            {
                s[i] = v[idx];
                idx++;
            }
        }
        return s;
    }
};