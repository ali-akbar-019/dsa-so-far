class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        //
        unordered_map<int, int> mp;
        int count = 0;
        int n = A.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            mp[A[i]]++;
            if (mp[A[i]] == 2)
            {
                count += 1;
            }
            mp[B[i]]++;
            if (mp[B[i]] == 2)
            {
                count += 1;
            }
            //
            res[i] = count;
        }
        return res;
    }
};