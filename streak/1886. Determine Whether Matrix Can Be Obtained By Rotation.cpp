class Solution
{
public:
    int n;
    void rotate_mat(vector<vector<int>> &mat)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(mat[i][j], mat[j][i]); // mirror ko swap kar do to transpose ajae ga
            }
        }
        // now reverse each row to get the 90deg clockwise rotation
        for (int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        n = mat.size();

        // max ham 4 bar rotate kar saktey ha to
        for (int c = 1; c <= 4; c++)
        {
            // now check the rotated mat each col and each row with the target matrix
            bool equal = true;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mat[i][j] != target[i][j])
                    {
                        equal = false;
                        break;
                    }
                }
                // agar break kar deya to agli rows check karne ki need nai q k nai equal
                if (!equal)
                {
                    break;
                }
            }
            // agar to equal then true
            if (equal)
            {
                return true;
            }
            // else rotate kar k fir se chek karo
            rotate_mat(mat);
        }
        return false;
    }
};