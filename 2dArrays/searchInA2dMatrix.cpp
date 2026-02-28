class Solution
{
public:
    bool findInRow(vector<vector<int>> &mat, int target, int row, int n)
    {
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int mid = (s + e) >> 1;
            if (mat[row][mid] == target)
            {
                return true;
            }
            else if (mat[row][mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &mat, int target)
    {
        int m = mat.size();
        int n = mat[0].size();
        // we will use the binary search on the rows
        int startingRow = 0;
        int endingRow = m - 1;
        int startingCol = 0;
        int endingCol = n - 1;
        while (startingRow <= endingRow)
        {
            int midRow = (startingRow + endingRow) >> 1;
            if (mat[midRow][startingCol] <= target && target <= mat[midRow][endingCol])
            {
                // if we found the row then
                return findInRow(mat, target, midRow, n);
            }
            else if (mat[midRow][startingCol] < target)
            {
                startingRow = midRow + 1;
            }
            else
            {
                endingRow = midRow - 1;
            }
        }
        return false;
    }
};