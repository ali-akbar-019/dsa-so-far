class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<int> actual_idx(n);
        iota(begin(actual_idx), end(actual_idx), 0);
        //
        vector<int> result;
        // now sort the actual indexes
        auto lambda = [&](int &i, int &j)
        {
            return positions[i] < positions[j];
        };
        sort(begin(actual_idx), end(actual_idx), lambda);
        // now we have the sorted actual positiosn
        stack<int> st;
        for (int &idx : actual_idx)
        {

            if (directions[idx] == 'R')
            {
                st.push(idx);
            }
            else
            {
                while (!st.empty() && healths[idx] > 0)
                {
                    int top_idx = st.top();
                    st.pop();
                    if (healths[top_idx] > healths[idx])
                    {
                        healths[top_idx] -= 1;
                        healths[idx] = 0;
                        st.push(top_idx);
                    }
                    else if (healths[top_idx] < healths[idx])
                    {
                        healths[top_idx] = 0;
                        healths[idx] -= 1;
                    }
                    else
                    {
                        healths[top_idx] = 0;
                        healths[idx] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (healths[i] > 0)
            {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};