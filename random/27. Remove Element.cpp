class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == val)
                i = nums[i] != val ? j : i;
            if (nums[j] != val)
                count++;
            if (nums[i] == val && nums[j] != val)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        return count;
    }
};