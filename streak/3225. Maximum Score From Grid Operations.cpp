// ========================== HELPER TYPEDEF ==========================
// Short alias for vector of long long to keep code cleaner
using vll = std::vector<long long>;

class Solution
{
public:
    // ========================== MAIN FUNCTION ==========================
    // Finds the maximum score possible by performing grid operations
    // Grid is n x n, and we can extract subrectangles from different columns
    long long maximumScore(vector<vector<int>> &grid)
    {
        int n = grid[0].size();

        // Edge case: single column grid has no operations possible
        if (n == 1)
        {
            return 0;
        }

        // ========================== DP STATE DEFINITION ==========================
        // dp[i][currH][prevH] = maximum score after processing column i
        //   - currH: height of rectangle extracted from column i (0 to n)
        //   - prevH: height of rectangle extracted from column i-1 (0 to n)
        // Height = number of rows starting from row 0
        vector<vector<vll>> dp(n, vector<vll>(n + 1, vll(n + 1, 0)));

        // ========================== OPTIMIZATION ARRAYS ==========================
        // prevMax[currH][prevH] = best score when previous height is exactly prevH,
        // considering all possible current heights up to currH (prefix maximum)
        vector<vll> prevMax(n + 1, vll(n + 1, 0));

        // prevSuffixMax[currH][prevH] = best score when current height is currH,
        // considering all possible previous heights from prevH to n (suffix maximum)
        vector<vll> prevSuffixMax(n + 1, vll(n + 1, 0));

        // colSum[c][r] = prefix sum of column c from row 0 to row r-1
        // Used to calculate sum of elements in a rectangle range efficiently
        vector<vll> colSum(n, vll(n + 1, 0));

        // ========================== PRECOMPUTE COLUMN PREFIX SUMS ==========================
        // For each column, compute cumulative sum of elements
        // colSum[c][r] = sum of grid[0..r-1][c]
        for (int c = 0; c < n; c++)
        {
            for (int r = 1; r <= n; r++)
            {
                colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
            }
        }

        // ========================== MAIN DP LOOP ==========================
        // Process each column from 1 to n-1
        // Column 0 acts as the base case (already initialized to 0)
        for (int i = 1; i < n; i++)
        {
            // For each possible height in current column
            for (int currH = 0; currH <= n; currH++)
            {
                // For each possible height in previous column
                for (int prevH = 0; prevH <= n; prevH++)
                {
                    // ========================== CASE 1: DECREASING HEIGHT ==========================
                    // If current height <= previous height (rectangle gets shorter or stays same)
                    // The elements in the gap are added to the score
                    if (currH <= prevH)
                    {
                        // Score = sum of elements from row currH to row prevH-1 in column i
                        long long extraScore =
                            colSum[i][prevH] - colSum[i][currH];

                        // Take best of all previous states with height >= prevH
                        dp[i][currH][prevH] =
                            std::max(dp[i][currH][prevH],
                                     prevSuffixMax[prevH][0] + extraScore);
                    }
                    // ========================== CASE 2: INCREASING HEIGHT ==========================
                    // If current height > previous height (rectangle gets taller)
                    // The elements in the previous column are subtracted as penalty
                    else
                    {
                        // Penalty = sum of elements from row prevH to row currH-1 in column i-1
                        long long extraScore =
                            colSum[i - 1][currH] - colSum[i - 1][prevH];

                        // Three options:
                        // 1. Take best state with height >= currH in previous column
                        // 2. Take direct previous state and subtract penalty
                        dp[i][currH][prevH] = std::max(
                            {dp[i][currH][prevH], prevSuffixMax[prevH][currH],
                             prevMax[prevH][currH] + extraScore});
                    }
                }
            }

            // ========================== UPDATE OPTIMIZATION ARRAYS ==========================
            // After computing all dp[i][currH][prevH] values, precompute max values
            // for efficient lookup in next iteration

            // For each possible current height
            for (int currH = 0; currH <= n; currH++)
            {
                // ========================== COMPUTE prevMax ==========================
                // prevMax[currH][prevH] = max(dp[i][currH][0..prevH]) - penalty
                // Stores the best score considering heights 0 to prevH in previous column
                prevMax[currH][0] = dp[i][currH][0];
                for (int prevH = 1; prevH <= n; prevH++)
                {
                    // If previous height > current height, we need to subtract penalty
                    long long penalty =
                        (prevH > currH) ? (colSum[i][prevH] - colSum[i][currH])
                                        : 0;

                    // Prefix maximum: best value so far for heights 0..prevH
                    prevMax[currH][prevH] =
                        std::max(prevMax[currH][prevH - 1],
                                 dp[i][currH][prevH] - penalty);
                }

                // ========================== COMPUTE prevSuffixMax ==========================
                // prevSuffixMax[currH][prevH] = max(dp[i][currH][prevH..n])
                // Stores the best score considering heights prevH to n in previous column
                prevSuffixMax[currH][n] = dp[i][currH][n];
                for (int prevH = n - 1; prevH >= 0; prevH--)
                {
                    // Suffix maximum: best value among heights prevH..n
                    prevSuffixMax[currH][prevH] = std::max(
                        prevSuffixMax[currH][prevH + 1], dp[i][currH][prevH]);
                }
            }
        }

        // ========================== EXTRACT ANSWER ==========================
        // After processing all columns, find the maximum score
        // Check all possible final heights in the last column (n-1)
        // Valid end states: dp[n-1][n][k] (column n-1 fully cleared)
        //                or dp[n-1][0][k] (column n-1 fully cleared from height 0)
        long long ans = 0;
        for (int k = 0; k <= n; k++)
        {
            ans = std::max({ans, dp[n - 1][n][k], dp[n - 1][0][k]});
        }

        return ans;
    }
};