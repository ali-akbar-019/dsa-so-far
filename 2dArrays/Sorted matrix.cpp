// User function Template for C++

class Solution
{
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
    {
        vector<int> sort_mat;
        // traverse the 2d matrix

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                sort_mat.push_back(Mat[i][j]);
            }
        }
        // sort the matrix
        sort(sort_mat.begin(), sort_mat.end());
        // put it in the orignal array
        int curr = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Mat[i][j] = sort_mat[curr];
                curr++;
            }
        }
        return Mat;
    }
};