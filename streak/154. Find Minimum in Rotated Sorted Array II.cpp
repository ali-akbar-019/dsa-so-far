class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // same part 1 wali logic ha yaha pe b
        // but we have  to skip the duplicates and is ki complexity
        // worst case me O(n) ban jaye gi
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            // yaha pe skip wali logic
            while (l < r && nums[l] == nums[l + 1])
                l++;
            while (r > l && nums[r] == nums[r - 1])
                r--;
            // ab binary search ki logic
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid; // q k mid b possible solution ho sakta ha
            }
        }
        return nums[l];
    }
};
