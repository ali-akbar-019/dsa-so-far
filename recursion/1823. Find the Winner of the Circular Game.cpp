class Solution
{
public:
    int find_index_of_winner(int n, int k)
    {
        if (n == 1)
        {
            return 0;
        }
        //
        int idx = find_index_of_winner(n - 1, k);
        idx = (idx + k) % n;
        return idx;
    }
    int findTheWinner(int n, int k)
    {

        int result_index = find_index_of_winner(n, k);
        return result_index + 1;
    }
};