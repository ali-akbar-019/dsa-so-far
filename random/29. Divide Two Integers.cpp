class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvi = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long result = 0;

        while (dvi >= dvs)
        {
            long long temp = dvs;
            long long multiple = 1;

            while ((temp << 1) <= dvi)
            {
                temp <<= 1;
                multiple <<= 1;
            }

            dvi -= temp;
            result += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            result = -result;

        return (int)result;
    }
};