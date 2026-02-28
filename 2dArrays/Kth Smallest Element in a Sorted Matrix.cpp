class Solution
{
public:
    int upperbound(vector<int> &matrix, int x, int n)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (matrix[mid] > x)
            {
                ans = mid;
                // find more smaller
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int countWhichSmallest(vector<vector<int>> &matrix, int mid, int n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += upperbound(matrix[i], mid, n);
        }
        return count;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        while (low < high)
        {
            int mid = (low + high) >> 1;
            int count = countWhichSmallest(matrix, mid, n);
            if (count < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};