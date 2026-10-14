class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        //
        int n = nums.size();
        // a2 - b2 + c2 - d2
        // a2 + c2 - (b2 + d2)
        // odd
        // a2 + c2 - b2
        for (int i = 0; i < n; i++)
        {
            long long v = nums[i];
            nums[i] = (v * v);
        }
        sort(begin(nums), end(nums));
        //
        long long small = 0;
        long long large = 0;
        for (int i = 0; i < n / 2; i++)
        {
            small += nums[i];
        }

        for (int i = n / 2; i < n; i++)
        {
            large += nums[i];
        }
        return large - small;
    }
};