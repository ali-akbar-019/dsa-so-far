class Solution
{
public:
    int smallestIndex(vector<int> &nums)
    {

        // first pe hi return kar jao jaha pe cond satisfy ho
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int temp = nums[i];
            int sum = 0;
            while (temp != 0)
            {
                int dig = temp % 10;
                sum += dig;
                temp = temp / 10;
            }
            if (sum == i)
            {
                return i;
            }
        }
        return -1;
    }
};