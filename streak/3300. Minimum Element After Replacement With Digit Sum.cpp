class Solution
{
public:
    int minElement(vector<int> &nums)
    {
        int minSum = INT_MAX;

        for (int num : nums)
        {
            int temp = num;
            int sum = 0;
            while (temp > 0)
            {
                sum += temp % 10;
                temp /= 10;
            }
            minSum = min(minSum, sum);
        }
        return minSum;
    }
};