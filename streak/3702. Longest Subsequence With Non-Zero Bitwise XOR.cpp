class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int resXor = 0;
        int allZero = true;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                allZero = false;
            }
            resXor ^= nums[i];
        }
        if (allZero)
        {
            return 0;
        }
        if (resXor == 0)
        {
            return n - 1;
        }
        else
        {
            return n;
        }
    }
};