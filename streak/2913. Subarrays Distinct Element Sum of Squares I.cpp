class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st;
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            st.clear();
            for (int j = i; j < n; j++)
            {
                st.insert(nums[j]);
                int size = st.size();
                result += size * size;
            }
        }
        return result;
    }
};