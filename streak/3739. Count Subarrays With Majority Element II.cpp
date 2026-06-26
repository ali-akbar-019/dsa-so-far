class Solution
{
public:
    long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        long long cummSum = 0;
        long long validLeftPoints = 0;
        int n = nums.size();
        long long result = 0;
        unordered_map<int, int> mp; // cummSum -> Count
        mp[0] = 1;                  // 0 ko one kar do k ham ne 0 aik bar dekha ha start me
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                validLeftPoints += mp[cummSum];
                cummSum += 1;
            }
            else
            {
                cummSum -= 1;
                validLeftPoints -= mp[cummSum];
            }
            mp[cummSum] += 1;
            result += validLeftPoints;
        }
        return result;
    }
};
