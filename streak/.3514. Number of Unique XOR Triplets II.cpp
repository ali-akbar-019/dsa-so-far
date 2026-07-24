class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        unordered_set<int> st;
        // first of all store the pairs XOR
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                st.insert(nums[i] ^ nums[j]);
            }
        }
        // ab is ka nums se xor ko
        unordered_set<int> ans;
        for (auto &pairXor : st)
        {
            for (auto &num : nums)
            {
                ans.insert(pairXor ^ num);
            }
        }
        return ans.size();
    }
};