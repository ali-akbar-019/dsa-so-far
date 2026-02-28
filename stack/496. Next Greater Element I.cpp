class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // first of al lets find the next greater of all the nums2
        stack<int> st;
        int n = nums2.size();
        vector<int> allNextGreater(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            // now we have the greater
            if (!st.empty())
            {
                allNextGreater[i] = st.top();
            }
            st.push(nums2[i]);
        }
        // now lets just find for the ones that are needed
        // first add to map
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums2[i]] = i;
        }
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
        {
            result.push_back(allNextGreater[mp[nums1[i]]]);
        }
        return result;
    }
};