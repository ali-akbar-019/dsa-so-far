class Solution
{
public:
    vector<int> maxValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftMax(n);
        vector<int> rightMin(n);
        // lets fill the leftMax and the right min
        leftMax[0] = nums[0];
        rightMin[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(nums[i], leftMax[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            rightMin[i] = min(nums[i], rightMin[i + 1]);
        }
        //------------------
        // now we have to check the conditions if the leftMax <= rightMin then ans = leftMax
        // if the leftMax >  rightMin then ans = ans[i + 1]
        vector<int> ans(n);
        ans[n - 1] = leftMax[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (leftMax[i] <= rightMin[i + 1])
            { // can not go to the right
                ans[i] = leftMax[i];
            }
            else
            {
                ans[i] = ans[i + 1];
            }
        }
        return ans;
    }
};