class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        // i - j ki game ha bs
        int m = mat.size();
        int n = mat[0].size();
        // take a map
        unordered_map<int, vector<int>> mp;
        //
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[i - j].push_back(mat[i][j]);
            }
        }
        // now sort them
        // we have something like this
        // 0 -> 3 2 1
        // sort
        for (auto &it : mp)
        {
            sort(it.second.begin(), it.second.end());
        }
        // now add to the array aagain
        // ulta traverse karo ta k hame vector se daal k pop karne k bad shifting na karni pare
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }
        return mat;
    }
};