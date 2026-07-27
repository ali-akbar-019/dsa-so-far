class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int fmax = INT_MIN;
        int smax = INT_MIN;
        for (auto &num : nums)
        {
            if (num > fmax)
            {
                smax = fmax;
                fmax = num;
            }
            else if (num == fmax || num > smax)
            {
                smax = num;
            }
        }
        return (fmax - 1) * (smax - 1);
    }
};