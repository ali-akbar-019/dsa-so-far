class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++)
        {

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            vector<int> nums;

            // top row
            for (int i = left; i <= right; i++)
            {
                nums.push_back(grid[top][i]);
            }

            // right column
            for (int j = top + 1; j <= bottom - 1; j++)
            {
                nums.push_back(grid[j][right]);
            }

            // bottom row
            for (int i = right; i >= left; i--)
            {
                nums.push_back(grid[bottom][i]);
            }

            // left column
            for (int j = bottom - 1; j >= top + 1; j--)
            {
                nums.push_back(grid[j][left]);
            }

            int len = nums.size();

            int normalized_k = k % len;

            rotate(nums.begin(),
                   nums.begin() + normalized_k,
                   nums.end());

            int idx = 0;

            // top row
            for (int i = left; i <= right; i++)
            {
                grid[top][i] = nums[idx++];
            }

            // right column
            for (int j = top + 1; j <= bottom - 1; j++)
            {
                grid[j][right] = nums[idx++];
            }

            // bottom row
            for (int i = right; i >= left; i--)
            {
                grid[bottom][i] = nums[idx++];
            }

            // left column
            for (int j = bottom - 1; j >= top + 1; j--)
            {
                grid[j][left] = nums[idx++];
            }
        }

        return grid;
    }
};