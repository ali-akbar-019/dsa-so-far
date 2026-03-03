class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        unordered_map<string, function<int(int, int)>> mp = {
            {"+", [](int a, int b)
             { return a + b; }},
            {"-", [](int a, int b)
             { return a - b; }},
            {"*", [](int a, int b)
             { return (long)a * (long)b; }},
            {"/", [](int a, int b)
             { return a / b; }},
        };
        stack<int> st;
        for (string &token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                // now operation
                int res = mp[token](a, b);
                st.push(res);
            }
            else
            {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};