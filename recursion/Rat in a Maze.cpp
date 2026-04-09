class Solution
{
public:
    vector<string> result;
    bool isSafe(int i, int j, int n)
    {
        if (i >= 0 && i < n && j >= 0 && j < n)
        {
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &maze, int i, int j, int n, string path)
    {
        if (!isSafe(i, j, n) || maze[i][j] == 0)
        {
            return; // not safe
        }
        if (i == n - 1 && j == n - 1)
        {
            // we have reached the dest so now store the currect path in the result
            result.push_back(path);
            return;
        }
        maze[i][j] = 0; // k we have visited the current
        // now discover all the paths
        //  D
        path.push_back('D');
        solve(maze, i + 1, j, n, path);
        path.pop_back();

        // L
        path.push_back('L');
        solve(maze, i, j - 1, n, path);
        path.pop_back();
        // R
        path.push_back('R');
        solve(maze, i, j + 1, n, path);
        path.pop_back();
        // U
        path.push_back('U');
        solve(maze, i - 1, j, n, path);
        path.pop_back();
        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // we will use recursion for this
        if (maze.size() == 0)
        {
            return {};
        }
        result.clear();
        // a rat can move U , D , L , R
        solve(maze, 0, 0, maze.size(), "");
        return result;
    }
};