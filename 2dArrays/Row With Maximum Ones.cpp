class Solution
{
public:
    int lowerbound(vector<int> &row, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (row[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int cnt_max = 0;
        int index = 0;

        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++)
        {
            int cnt = n - lowerbound(mat[i], n, 1);
            if (cnt > cnt_max)
            {
                cnt_max = cnt;
                index = i;
            }
        }

        return {index, cnt_max};
    }
};

// not sorted rows
class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int n = mat[0].size();
        int m = mat.size();
        int maxCount = 0;
        int index = 0;
        for (int i = 0; i < m; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                count += mat[i][j];
            }
            if (count > maxCount)
            {
                maxCount = count;
                index = i;
            }
        }
        return {index, maxCount};
    }
};