class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        //
        unordered_map<int, int> mp;
        int n = nums.size();
        if (k == n)
        {
            return *max_element(begin(nums), end(nums));
        }
        for (auto &num : nums)
        {
            mp[num]++;
        }

        vector<int> unique;
        for (auto const &num : mp)
        {

            if (num.second == 1)
            {
                unique.push_back(num.first);
            }
        }
        // agar k === 1 then unique ka max ho ga ans

        if (k == 1)
        {
            int ans = unique.size() != 0 ? *max_element(begin(unique), end(unique)) : -1;
            return ans;
        }
        int first = mp[nums[0]] == 1 ? nums[0] : -1;
        int last = mp[nums[n - 1]] == 1 ? nums[n - 1] : -1;
        // agar 2 ya n-1 k between ho then jst obv se pata chalta ha k 1st and lst hi unique reh sakte ha
        // and k > n ho then -1 hi ans ha
        return max(first, last);
    }
};