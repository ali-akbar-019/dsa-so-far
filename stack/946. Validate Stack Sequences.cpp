class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int m = pushed.size();
        int i = 0;
        int j = 0;
        stack<int> st;
        while (i < m && j < m)
        {
            st.push(pushed[i]);
            while (j < m && !st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();
    }
};