class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int totalSum = 0;
        for (int &num : nums)
        {
            totalSum += num;
        }
        //
        int cs = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int ls = cs;
            int rs = totalSum - cs - nums[i];
            if (ls == rs)
            {
                return i;
            }
            cs += nums[i];
        }
        return -1;
    }
};