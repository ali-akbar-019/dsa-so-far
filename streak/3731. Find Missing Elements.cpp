class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int maxi = *max_element(begin(nums), end(nums));
        int mini = *min_element(begin(nums), end(nums));
        unordered_set<int> st(begin(nums), end(nums));
        vector<int> ans;
        for (int i = mini; i <= maxi; i++)
        {
            if (!st.count(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};