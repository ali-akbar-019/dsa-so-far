class Solution
{
public:
    int upperbound(vector<int> &mat, int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (mat[mid] > x)
            {
                ans = mid;
                // find more smallest
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int countLessThanEqualTo(vector<vector<int>> &mat, int n, int m, int x)
    {
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cnt += upperbound(mat[i], n, x);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        // find low and high
        for (int i = 0; i < m; i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][n - 1]);
        }
        // find the median
        int req = (n * m) / 2;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int cnt = countLessThanEqualTo(mat, n, m, mid);
            if (cnt <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
