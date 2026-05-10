class Solution
{
public:
    int solve(int i, vector<int> &nums, int n, int target, vector<int> &dp)
    {
        // formula abs(nums[i] - nums[j]) <= target == -target <= nums[j] - nums[i]  <= target
        if (i == n - 1)
        {
            return 0;
        }
        if (dp[i] != INT_MIN)
        {
            return dp[i];
        }
        //
        int result = INT_MIN;
        // har aik i k leye check karo, k j kaha kaha valid ha
        // then waha jump karo and same check karo
        // tm ne qareeb jump kar k max number of jumps batane ha
        for (int j = i + 1; j < n; j++)
        {
            if (abs(nums[i] - nums[j]) <= target)
            {
                int ans = 1 + solve(j, nums, n, target, dp);
                result = max(result, ans);
            }
        }

        return dp[i] = result;
    }
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MIN); // bcz -1 is a valid answer
        int ans = solve(0, nums, n, target, dp);
        return ans < 0 ? -1 : ans;
    }
};

// -----------------------
