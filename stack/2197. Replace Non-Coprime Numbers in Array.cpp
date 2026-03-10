class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> result;
        int n = nums.size();

        for (int &num : nums)
        {
            //
            while (!result.empty())
            {
                int GCD = gcd(num, result.back());
                if (GCD == 1)
                {
                    break;
                }
                int prev = result.back();
                result.pop_back();
                int lcm = prev / GCD * num;
                num = lcm;
            }
            result.push_back(num);
        }
        return result;
    }
};