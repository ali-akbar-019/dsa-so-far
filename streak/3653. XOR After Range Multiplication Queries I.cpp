class Solution
{
public:
    int M = 1e9 + 7;
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        for (auto &q : queries)
        {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            //---
            // apply the queries
            for (int idx = l; idx <= r; idx += k)
            {
                nums[idx] = (1LL * nums[idx] * v) % M;
            }
        }
        // now do the xor
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res = nums[i] ^ res;
        }
        return res;
    }
};