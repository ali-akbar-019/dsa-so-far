class Solution
{
public:
    int maxProduct(int n)
    {
        //
        vector<int> vec;
        while (n != 0)
        {
            int dig = n % 10;
            vec.push_back(dig);
            n = n / 10;
        }
        //
        sort(begin(vec), end(vec));
        int sz = vec.size();
        int ans = vec[sz - 1] * vec[sz - 2];
        return ans;
    }
};