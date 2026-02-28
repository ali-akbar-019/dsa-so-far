class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        // pehle sort kar do
        sort(nums.begin(), nums.end());
        // ab check karo k koi se teen points ka sum a+b> c ata ha , agar yes then triangle ha or sum bej do
        int n = nums.size();
        for (int i = n - 3; i >= 0; i--)
        {
            if (nums[i] + nums[i + 1] > nums[i + 2])
            {
                // a + b > c
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};