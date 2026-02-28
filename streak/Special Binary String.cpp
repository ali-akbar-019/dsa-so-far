class Solution
{
public:
    string makeLargestSpecial(string s)
    {
        int sum = 0;
        int start = 0;
        vector<string> specials;
        for (int i = 0; i < s.length(); i++)
        {
            sum += s[i] == '1' ? 1 : -1;
            if (sum == 0)
            {
                // we found a special string
                // call the recursion
                string inner = s.substr(start + 1, i - start - 1);
                string RecSolve = '1' + makeLargestSpecial(inner) + '0';
                specials.push_back(RecSolve);
                start = i + 1;
            }
        }
        // now reverse the specials array in decending order
        sort(specials.begin(), specials.end(), greater<string>());
        // now make it a string and return it
        string ans;
        for (string &str : specials)
        {
            ans += str;
        }
        return ans;
    }
};