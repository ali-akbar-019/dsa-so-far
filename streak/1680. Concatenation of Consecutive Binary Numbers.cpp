class Solution
{
public:
    int M = 1e9 + 7;
    int concatenatedBinary(int n)
    {
        int bitsLength = 0;
        long long result = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((i & (i - 1)) == 0)
            {
                // means power of two
                bitsLength++;
            }
            // now update the result
            result = ((result << bitsLength) + i) % M;
        }
        return result;
    }
};