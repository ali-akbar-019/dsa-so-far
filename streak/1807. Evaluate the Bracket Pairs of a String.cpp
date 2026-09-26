class Solution
{
public:
    string evaluate(string s, vector<vector<string> > &knowledge)
    {
        // take a map to store the knowledge so that we can access it in o 1
        unordered_map<string, string> mp;
        int n = s.length();
        for (auto &words : knowledge)
        {
            mp[words[0]] = words[1];
        }
        //
        int i = 0;
        string ans = "";
        while (i < n)
        {
            if (s[i] == '(')
            {
                int j = s.find(')', i + 1);
                string temp = s.substr(i + 1, j - i - 1);
                ans += mp.count(temp) ? mp[temp] : "?";
                i = j; // j ajaye ga closing pe
            }
            else
            {
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
};