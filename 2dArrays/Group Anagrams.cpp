class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // take a make
        unordered_map<string, vector<string>> mp;
        // result array
        vector<vector<string>> result;
        // loop karo sab pe
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            string temp = strs[i];
            sort(begin(temp), end(temp));
            mp[temp].push_back(strs[i]);
        }
        // result me dal do
        for (auto it : mp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};