class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        int maxDiff = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            maxDiff = max(maxDiff, abs(nums1[i] - nums2[i]));
        }

        vector<int> diffCount(maxDiff + 1, 0);
        for (int i = 0; i < n; i++)
        {
            diffCount[abs(nums1[i] - nums2[i])]++;
        }

        long long K = (long long)k1 + k2;
        for (int i = maxDiff; i > 0 && K > 0; i--)
        {
            long long opsCanPerf = min(K, (long long)diffCount[i]);
            diffCount[i] -= (int)opsCanPerf;
            diffCount[i - 1] += (int)opsCanPerf;
            K -= opsCanPerf;
        }

        long long res = 0;
        for (int i = 1; i <= maxDiff; i++)
        {
            res += (long long)i * i * diffCount[i];
        }
        return res;
    }
};