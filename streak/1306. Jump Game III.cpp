class Solution
{
public:
    int n;
    bool DFS(vector<int> &arr, int i)
    {
        if (i < 0 || i >= n || arr[i] < 0)
        {
            return false;
        }
        // agar hame mil gaya zero then return true
        if (arr[i] == 0)
        {
            return true;
        }
        // ise visit kar rahe ha ham abi
        arr[i] *= -1;
        // options ha simple se
        bool a = DFS(arr, i + arr[i]);
        bool b = DFS(arr, i - arr[i]);
        return a || b;
    }
    bool canReach(vector<int> &arr, int start)
    {
        // simple recursion
        n = arr.size();
        return DFS(arr, start);
    }
};