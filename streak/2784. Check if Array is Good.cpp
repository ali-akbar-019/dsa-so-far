class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        int maxi = nums[0];
        int n = nums.size() - 1;
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > n || nums[i] <= 0)
                return false;
            freq[nums[i]]++;
            if (freq[nums[i]] > 2)
                return false;
            if (maxi < nums[i])
            {
                maxi = nums[i];
            }
        }
        if (n != maxi)
            return false;
        // check 1 to n -1
        for (int i = 1; i < n; i++)
        {
            if (freq[i] != 1)
                return false;
        }
        if (freq[n] != 2)
            return false;
        return true;
    }
};