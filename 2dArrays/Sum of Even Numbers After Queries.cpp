class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        //
        int n = nums.size();
        int sumEven = 0;
        for (int &num : nums)
        {
            if (num % 2 == 0)
                sumEven += num;
        }
        //
        // now queries check karo
        vector<int> ans;
        int nQ = queries.size();
        for (int i = 0; i < nQ; i++)
        {
            int val = queries[i][0];
            int idx = queries[i][1];
            if (nums[idx] % 2 == 0)
            {
                sumEven -= nums[idx];
            }
            // perform the operation
            nums[idx] += val;
            if (nums[idx] % 2 == 0)
            {
                sumEven += nums[idx];
            }
            ans.push_back(sumEven);
        }
        return ans;
    }
};