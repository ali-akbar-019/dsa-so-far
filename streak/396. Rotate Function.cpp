class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        // observe a simple pattern that the next func value depends on the prev one + toatl sum - n times the value that is supposed to be zero this time
        int f0 = 0;
        int total_sum = 0;
        for (int i = 0; i < n; i++)
        {
            f0 += i * nums[i];
            total_sum += nums[i];
        }
        //
        int max_value = f0;
        int prev_func_value = f0;
        for (int k = 1; k < n; k++)
        {
            int curr_func_value = prev_func_value + total_sum - n * (nums[n - k]);
            max_value = max(max_value, curr_func_value);
            prev_func_value = curr_func_value;
        }
        return max_value;
    }
};