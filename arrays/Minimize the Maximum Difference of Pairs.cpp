class Solution
{
public:
    bool isValid(vector<int> &nums, int mid, int p)
    {
        int countPairs = 0;
        int i = 0;
        int n = nums.size();
        while (i < n - 1)
        {
            if ((nums[i + 1] - nums[i]) <= mid)
            {
                countPairs++;
                i += 2;
            }
            else
            {
                i++;
            }
        }
        return countPairs >= p;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        // in this question we will use the binary search on the ans
        // first sort kar do
        sort(begin(nums), end(nums));
        // binary search
        int n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0];
        int result = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (isValid(nums, mid, p))
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};