class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;

        for (int &as : asteroids)
        {
            while (!st.empty() && st.top() > 0 && as < 0)
            {
                int sum = as + st.top();
                if (sum == 0)
                {
                    st.pop();
                    as = 0;
                    break;
                }
                else if (sum < 0)
                {
                    st.pop();
                }
                else
                {
                    as = 0;
                    break;
                }
            }
            if (as != 0)
            {
                st.push(as);
            }
        }
        //
        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--)
        {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};