class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        // first of all we hae to rorate 90 deg
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> transpose(n, vector<char>(m, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                transpose[j][i] = boxGrid[i][j];
            }
        }
        //
        for (auto &row : transpose)
        {
            reverse(row.begin(), row.end());
        }
        // now the gravity
        for (int j = 0; j < m; j++)
        {
            int spaceRow = n - 1;
            for (int i = n - 1; i >= 0; i--)
            {
                if (transpose[i][j] == '*')
                {
                    spaceRow = i - 1;
                    continue;
                }
                if (transpose[i][j] == '#')
                {
                    transpose[i][j] = '.';
                    transpose[spaceRow][j] = '#';
                    spaceRow--;
                }
            }
        }
        return transpose;
    }
};