class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        // simplest method use another vector
        vector<int> ans;
        for (auto &x : nums)
        {
            if (x < pivot)
            {
                ans.push_back(x);
            }
        }
        for (auto &x : nums)
        {
            if (x == pivot)
            {
                ans.push_back(x);
            }
        }
        for (auto &x : nums)
        {
            if (x > pivot)
            {
                ans.push_back(x);
            }
        }

        // end me return kar do ans ko
        return ans;
    }
};