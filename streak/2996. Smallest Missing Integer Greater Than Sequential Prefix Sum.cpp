class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int n = nums.size();
        int seqSum = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == (nums[i - 1] + 1))
            {

                seqSum += nums[i];
            }
            else
            {
                break;
            }
        }
        //
        unordered_set<int> st(begin(nums), end(nums));
        while (st.count(seqSum))
        {
            seqSum++; // greater than or equal to
        }
        return seqSum;
    }
};