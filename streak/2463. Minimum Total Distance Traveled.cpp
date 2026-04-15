class Solution
{
public:
    typedef long long ll;
    ll solve(int i, int j, vector<int> &robot, vector<int> &pos, vector<vector<ll>> &t)
    {
        if (i >= robot.size())
        {
            return 0;
        }
        if (j >= pos.size())
        {
            return 1e12;
        }
        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        //
        ll take = abs(robot[i] - pos[j]) + solve(i + 1, j + 1, robot, pos, t);
        ll skip = solve(i, j + 1, robot, pos, t);
        return t[i][j] = min(take, skip);
    }
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        // sort kar do
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        //
        /// ab exapand kar do factory array ko ta k limit ki tension khtm ho jaye
        vector<int> positions;
        for (int i = 0; i < factory.size(); i++)
        {
            for (int j = 0; j < factory[i][1]; j++)
            {
                positions.push_back(factory[i][0]);
            }
        }
        // mem array
        int n = robot.size();
        int m = positions.size();

        vector<vector<ll>> t(n + 1, vector<ll>(m + 1, -1));
        //
        return solve(0, 0, robot, positions, t);
    }
};