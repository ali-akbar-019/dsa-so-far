class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        // e z
        unordered_set<int> st(begin(nums), end(nums));
        // multiples
        int count = 1;
        while (true)
        {
            int temp = k * count;
            if (!st.count(temp))
            {
                return temp;
            }
            count++;
        }
        return -1;
    }
};