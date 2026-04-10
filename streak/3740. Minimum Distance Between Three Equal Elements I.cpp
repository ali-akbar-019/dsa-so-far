class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        // simple sa question ha
        // i - j + j -k + k - 1 = 2*(k -i)
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        //
        // now check k kis ki indeces greater than equal to three ha bs use hi check karo
        for (auto &m : mp)
        {
            vector<int> v = m.second;
            //
            if (v.size() < 3)
            {
                continue;
            }
            //

            for (int i = 0; i + 2 < v.size(); i++)
            {
                int dist = 2 * (v[i + 2] - v[i]);
                ans = min(ans, dist);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
