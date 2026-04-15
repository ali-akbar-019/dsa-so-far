class Solution
{
public:
    bool solve(int i, int currSum, int &n, string &num, vector<vector<int>> &t)
    {
        if (i == num.size())
        {
            return currSum == n;
        }
        //
        if (currSum > n)
        {
            return false;
        }
        if (t[i][currSum] != -1)
        {
            return t[i][currSum];
        }
        ///
        bool possible = false;
        for (int j = i; j < num.size(); j++)
        {
            string sub = num.substr(i, j - i + 1);
            possible = possible || solve(j + 1, currSum + stoi(sub), n, num, t);
            if (possible)
            {
                return t[i][currSum] = true;
            }
        }
        return t[i][currSum] = false;
    }
    int punishmentNumber(int n)
    {
        //

        int punish = 0;

        for (int i = 1; i <= n; i++)
        {
            int sqNum = i * i;
            string num = to_string(sqNum);
            vector<vector<int>> t(num.length(), vector<int>(i + 1, -1));
            if (solve(0, 0, i, num, t))
            {
                punish += sqNum;
            }
        }
        return punish;
    }
};