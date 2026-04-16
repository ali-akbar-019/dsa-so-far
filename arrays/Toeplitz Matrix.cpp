/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Toeplitz Matrix (LeetCode 766)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  A TOEPLITZ MATRIX is one where all elements on diagonals are the same.
  Example: [[1,2,3],[5,1,2],[9,5,1]] is Toeplitz (each diagonal has same values)

ALGORITHM: Diagonal Element Comparison
  KEY IDEA: In a Toeplitz matrix, matrix[i][j] == matrix[i-1][j-1]
  (Each element equals its diagonal predecessor)

  APPROACH:
  1. Skip first row and first column (no predecessors)
  2. For all other elements: verify matrix[i][j] == matrix[i-1][j-1]
  3. If any mismatch, return false
  4. Otherwise return true

TIME COMPLEXITY: O(m*n) - visit each element once
SPACE COMPLEXITY: O(1) - constant space

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int> > &matrix)
    {
        // pehli row or pehle column ko ignore kar do q k un k peche koi nai diagnol jis ko compare kare
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] != matrix[i - 1][j - 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};