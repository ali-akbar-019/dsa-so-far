class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int peak = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                peak++;
            }
        }
        // aik bar peak ana chahie tb hi sorted and rotated ho ga
        return peak <= 1;
    }
};