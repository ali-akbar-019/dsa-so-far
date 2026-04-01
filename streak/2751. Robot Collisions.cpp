class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        // first we need the actual indexes
        int n = positions.size();
        vector<int> actual_index(n, 0);
        for (int i = 0; i < n; i++)
        {
            actual_index[i] = i;
        }
        //
        // now we gotta sort them according to the order the robots are in the number line

        auto lambda = [&](int &i, int &j)
        {
            // we gotta sort based on the positions array
            return positions[i] < positions[j];
        };
        sort(actual_index.begin(), actual_index.end(), lambda);
        //
        // ab stack banao or direction k base me calc karo
        stack<int> st;
        for (int &idx : actual_index)
        {
            if (directions[idx] == 'R')
            {
                st.push(idx); // check karo agar right pe ja raha to bs insert kar do ise
            }
            else
            {
                // Left mil gaya
                while (!st.empty() && healths[idx] > 0)
                {
                    // jab tk stack empty na ho ya to jo current robot ha us ki health zero na ho jaye
                    int top_idx = st.top();
                    st.pop();
                    if (healths[idx] > healths[top_idx])
                    {
                        healths[idx] -= 1;
                        healths[top_idx] = 0;
                    }
                    else if (healths[top_idx] > healths[idx])
                    {
                        healths[idx] = 0;
                        healths[top_idx] -= 1;
                        // push it back
                        st.push(top_idx);
                    }
                    else
                    {
                        healths[idx] = 0;
                        healths[top_idx] = 0;
                    }
                }
            }
        }
        //
        vector<int> result;
        for (int i = 0; i < healths.size(); i++)
        {
            if (healths[i] > 0)
            {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};