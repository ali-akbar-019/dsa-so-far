class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int posMult = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int negMult = nums[0] * nums[1] * nums[n - 1];
        return max(posMult, negMult);
    }
};