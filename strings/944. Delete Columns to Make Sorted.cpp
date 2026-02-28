class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int count = 0;
        int n = strs.size();
        int k = strs[0].size();
        if (n == 0)
        {
            return 0;
        }
        for (int i = 0; i < k; i++)
        {
            for (int j = 1; j < n; j++)
            {
                // i   j
                // zyx wvu tsr
                if (strs[j][i] < strs[j - 1][i])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};