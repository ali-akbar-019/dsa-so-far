class Solution
{
public:
    void solve(int curr, int n, vector<int> &result)
    {
        if (curr > n)
        {
            return;
        }
        //
        result.push_back(curr); // is ko result me dalo and is k sath baqi combinations check karo
        //
        // ab 1 se 9 tk jao
        for (int i = 0; i <= 9; i++)
        {
            int new_num = (curr * 10) + i;
            if (new_num > n)
            {
                return;
            }
            solve(new_num, n, result);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        // we have to check from 1 till n right
        vector<int> result;
        // 9 se oper lexicographical me duplicates ajaye ge jo ham ne pehle hi dale hoe result me
        for (int startNum = 1; startNum <= 9; startNum++)
        {
            solve(startNum, n, result);
        }
        return result;
    }
};