class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {

        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> cnt(mx + 1, 0);

        // Frequency
        for (int x : nums)
            cnt[x]++;

        // Count numbers divisible by i
        for (int i = 1; i <= mx; i++)
        {
            for (int j = i * 2; j <= mx; j += i)
            {
                cnt[i] += cnt[j];
            }
        }

        // Number of pairs divisible by i
        for (int i = 1; i <= mx; i++)
        {
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        }

        // Inclusion-Exclusion
        for (int i = mx; i >= 1; i--)
        {
            for (int j = i * 2; j <= mx; j += i)
            {
                cnt[i] -= cnt[j];
            }
        }

        // Prefix Sum
        for (int i = 1; i <= mx; i++)
        {
            cnt[i] += cnt[i - 1];
        }

        vector<int> ans;
        for (long long q : queries)
        {
            ans.push_back(lower_bound(cnt.begin(), cnt.end(), q + 1) - cnt.begin());
        }

        return ans;
    }
};