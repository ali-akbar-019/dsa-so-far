class Solution
{
public:
    vector<int> t;
    int solve(vector<int> &arr, int &n, int i, int &d)
    {
        if (t[i] != -1)
        {
            return t[i];
        }
        int result = 1; // count the current index
        // left
        for (int j = i - 1; j >= max(0, i - d); j--)
        {
            if (arr[j] >= arr[i])
            {
                break;
            }
            //
            result = max(result, 1 + solve(arr, n, j, d));
        }
        // right
        for (int j = i + 1; j <= min(n - 1, i + d); j++)
        {
            if (arr[j] >= arr[i])
            {
                break;
            }
            //
            result = max(result, 1 + solve(arr, n, j, d));
        }
        return t[i] = result;
    }
    int maxJumps(vector<int> &arr, int d)
    {
        // will solve the problem using the recursion and the Dp
        int result = 0;
        // initialize the dp array
        int n = arr.size();
        t.resize(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            // har aik index se check karo
            result = max(result, solve(arr, n, i, d));
        }
        return result;
    }
};