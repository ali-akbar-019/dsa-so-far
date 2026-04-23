class Solution
{
public:
    typedef long long ll;

    vector<ll> distance(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, ll> indexCount;
        unordered_map<int, ll> indexSum;
        vector<ll> res(n, 0);

        // left → right
        for (int i = 0; i < n; i++)
        {
            ll count = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];
            res[i] += (ll)i * count - sum;

            indexCount[nums[i]]++;
            indexSum[nums[i]] += i;
        }

        indexCount.clear();
        indexSum.clear();

        // right → left
        for (int i = n - 1; i >= 0; i--)
        {
            ll count = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];
            res[i] += sum - (ll)i * count;

            indexCount[nums[i]]++;
            indexSum[nums[i]] += i;
        }

        return res;
    }
};