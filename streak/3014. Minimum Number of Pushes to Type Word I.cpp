class Solution
{
public:
    int minimumPushes(string word)
    {
        unordered_map<int, int> mp;
        int assign_key = 2;
        int res = 0;
        for (auto &w : word)
        {
            if (assign_key > 9)
                assign_key = 2;
            mp[assign_key]++;
            res += mp[assign_key];
            assign_key++;
        }
        return res;
    }
};