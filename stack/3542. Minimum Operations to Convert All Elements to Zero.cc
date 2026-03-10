class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        // this is a problem of monotonic stack
        stack<int> st;
        int opr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                while (!st.empty())
                {
                    st.pop(); // reset stack
                }
                continue;
            }
            while (!st.empty() && st.top() > nums[i])
            {
                st.pop();
            }
            //
            if (st.empty() || st.top() < nums[i])
            {
                st.push(nums[i]);
                opr++;
            }
        }
        return opr;
    }
};