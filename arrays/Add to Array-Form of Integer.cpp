class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        // simple
        int n = num.size();
        int i = n - 1;
        vector<int> result;
        while (i >= 0 || k > 0)
        {
            if (i >= 0)
            {
                k += num[i];
            }
            // ab add kar do ans me
            result.push_back(k % 10);
            i--;
            k /= 10;
        }
        // reverse kr do
        reverse(begin(result), end(result));
        return result;
    }
};