class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        // lets do whats asked..

        int n = nums.size();
        vector<int> prefixGcd(n, -1);
        // now pass to make this prefixGrid
        prefixGcd[0] = nums[0];
        int mxi = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > mxi)
            {
                mxi = nums[i];
            }
            prefixGcd[i] = __gcd(mxi, nums[i]);
        }
        // sort kar do
        sort(begin(prefixGcd), end(prefixGcd));
        // two pointers
        long long sum = 0;
        int l = 0;
        int r = prefixGcd.size() - 1;
        while (l < r)
        {
            sum += 1LL * (__gcd(prefixGcd[l], prefixGcd[r]));
            l++;
            r--;
        }
        return sum;
    }
};