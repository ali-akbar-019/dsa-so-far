class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        // first map me sab dal do
        unordered_map<int, int> mp;
        int n = changed.size();
        if (n % 2 == 1)
        {
            return {};
        }
        for (int &num : changed)
        {
            mp[num]++;
        }
        // now sort kar do array ko
        sort(changed.begin(), changed.end());
        // ans array
        vector<int> ans;
        // now check karo har aik pe jaa k k us ka twice present ha k nai
        for (int &num : changed)
        {
            int twice = num * 2;
            if (mp[num] == 0)
            {
                continue;
            }
            //
            if (mp.find(twice) == mp.end() || mp[twice] == 0)
            {
                return {};
            }
            // else ans me daal do ,q k is ka twice present ha
            ans.push_back(num);
            mp[num]--;
            mp[twice]--;
        }
        return ans;
    }
};