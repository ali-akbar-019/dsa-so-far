class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        //
        int n = matrix.size();
        int m = matrix[0].size();
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = n - 1;
        int endingCol = m - 1;
        //
        vector<int> ans;
        while (startingRow <= endingRow && startingCol <= endingCol)
        {
            // top
            for (int j = startingCol; j <= endingCol; j++)
            {
                ans.push_back(matrix[startingRow][j]);
            }
            // right
            for (int i = startingRow + 1; i <= endingRow; i++)
            {
                ans.push_back(matrix[i][endingCol]);
            }

            // bottom
            for (int j = endingCol - 1; j >= startingCol; j--)
            {
                // egde case
                if (startingRow == endingRow)
                {
                    break; // we have already print it
                }
                ans.push_back(matrix[endingRow][j]);
            }
            // left
            for (int i = endingRow - 1; i >= startingRow + 1; i--)
            {
                if (startingCol == endingCol)
                {
                    break; // we have already print it
                }
                ans.push_back(matrix[i][startingCol]);
            }
            startingRow++;
            startingCol++;
            endingRow--;
            endingCol--;
        }
        return ans;
    }
};