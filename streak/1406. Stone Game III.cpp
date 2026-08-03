class Solution
{
public:
    int n;
    vector<int> t;
    int solve(int i, vector<int> &stoneValue)
    {
        if (i >= n)
            return 0;
        if (t[i] != -1)
            return t[i];
        // ya to 1 le sakta ya 2 and ya 3
        // jo chose kar le baqi fir bob chose kare ga to wo hame apne ans se minus karna ho ga
        // agar hamara result fir positive aya then ham jeet gaye
        // if equal then tie
        // else yar fir ham har gaye
        int result = stoneValue[i] - solve(i + 1, stoneValue);
        if (i + 1 < n)
        {
            result = max(result, (stoneValue[i] + stoneValue[i + 1]) - solve(i + 2, stoneValue));
        }
        if (i + 2 < n)
        {
            result = max(result, (stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2]) - solve(i + 3, stoneValue));
        }
        return t[i] = result;
    }
    string stoneGameIII(vector<int> &stoneValue)
    {
        n = stoneValue.size();
        t.resize(n + 1, -1);
        int result = solve(0, stoneValue);
        if (result == 0)
            return "Tie";
        if (result > 0)
        {
            return "Alice";
        }
        else
        {
            return "Bob";
        }
    }
};