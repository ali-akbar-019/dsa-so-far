class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // first transpose nikalo
        // then har row ko reverse karo
        // ho gaya 90 deg rotate
        // 1. transpose
        int m = matrix.size();
        int n = m; // same ha row and col
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]); // ho gaya transpose
            }
        }
        // 2.reverse
        for (int i = 0; i < m; i++)
        {
            reverse(begin(matrix[i]), end(matrix[i]));
        }
        // complete
    }
};