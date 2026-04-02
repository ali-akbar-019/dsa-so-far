class Solution
{
public:
    void insertAtBottom(stack<int> &st, int el)
    {
        if (st.empty())
        {
            st.push(el);
            return;
        }
        //
        int top = st.top();
        st.pop();
        insertAtBottom(st, el);
        st.push(top);
    }

    void reverseStack(stack<int> &st)
    {
        // code here
        if (st.empty())
        {
            return;
        }
        //
        int top = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, top);
    }
};