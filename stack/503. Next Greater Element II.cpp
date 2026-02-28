class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        vector<int> result(n, -1);
        for (int i = n * 2 - 1; i >= 0; i--)
        {
            int idx = i % n;
            while (!st.empty() && st.top() <= nums[idx])
            {
                st.pop();
            }
            if (!st.empty() && i < n)
            {
                result[idx] = st.top();
            }
            st.push(nums[idx]);
        }
        return result;
    }
};