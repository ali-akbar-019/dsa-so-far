class Solution
{
public:
    int MOD = 1e9 + 7;
    int t[201][201][201];
    int solve(int i, vector<int> &nums, int first, int second)
    {
        if (i >= nums.size())
        {
            // check karo k gcd seq 1 and 2 same ha
            bool bothNotZero = first != 0 && second != 0;
            // check same
            if (bothNotZero && first == second)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (t[i][first][second] != -1)
            return t[i][first][second];
        // skip - gcd or first and second remains the same as prev
        int skip = solve(i + 1, nums, first, second);
        // take in seq 1
        int take1 = solve(i + 1, nums, __gcd(first, nums[i]), second);
        // take in seq 2
        int take2 = solve(i + 1, nums, first, __gcd(second, nums[i]));

        // ab in ka sum return kar do
        int sum = (1LL * skip + take1 + take2) % MOD;
        return t[i][first][second] = sum;
    }
    int subsequencePairCount(vector<int> &nums)
    {
        // it was too simple,
        // jab b subsequence ajaye then try with recursion and then try to memoize it using the dp
        int n = nums.size();
        int first = 0;
        int second = 0;
        int count = 0;
        memset(t, -1, sizeof(t));
        // har aik index pe ja k us ko skip, take in seq 1 or take in seq 2
        count = solve(0, nums, first, second);
        return count;
    }
};