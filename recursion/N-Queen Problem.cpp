class Solution
{
public:
    unordered_set<int> cols;
    unordered_set<int> diagnols;
    unordered_set<int> antidiagnols;

    vector<vector<int>> result;
    void solve(int n, int row, vector<int> curr)
    {
        if (row >= n)
        {
            result.push_back(curr);
            return;
        }
        //
        // now the choices
        // check each col of the curr row weather we can place or not
        for (int col = 0; col < n; col++)
        {
            int diagConst = row + col;
            int antiDiagConst = row - col;
            if (cols.find(col) != cols.end() ||
                diagnols.find(diagConst) != diagnols.end() ||
                antidiagnols.find(antiDiagConst) != antidiagnols.end())
            {
                continue;
            }
            else
            {
                curr.push_back(col + 1);
                // baqi ko solve kar lao
                cols.insert(col);
                diagnols.insert(diagConst);
                antidiagnols.insert(antiDiagConst);

                solve(n, row + 1, curr);
                // backtrack
                curr.pop_back();
                cols.erase(col);
                diagnols.erase(diagConst);
                antidiagnols.erase(antiDiagConst);
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        // we will use recursion for this
        vector<int> curr; //
        solve(n, 0, curr);
        return result;
    }
};