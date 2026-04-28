class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int m = grid.size();
        int n = grid[0].size();
        // make a 1d vector
        vector<int> vec;
        // push the 2d to the 1d
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vec.push_back(grid[i][j]);
            }
        }
        // ab sort karo lo and mid wala le lena, bcz agar ham extreme min lete ha ya extreme max then zyada operations lagte ha and mid ko ham le then hame min ko mid banane me b kam operationss lage ge and max ko b mid banane me
        // pehle sort kar do yar warna mid wala kaise theek me aye ga
        sort(vec.begin(), vec.end());
        int L = vec.size(); // m*n
        int target = vec[L / 2];
        // ab  har number check karo k kitne operations lagte ha us ko ye banane me
        int result = 0;
        for (auto &num : vec)
        {
            if (num % x != target % x)
            {
                return -1;
            }
            result += abs(target - num) / x;
        }
        return result;
    }
};