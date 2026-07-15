class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {
        long long evenSum = 0;
        long long oddSum = 0;
        int evenNum = 0;
        int oddNum = 1;
        for (int i = 1; i <= n; i++)
        {
            evenSum += evenNum;
            oddSum += oddNum;
            evenNum += 2;
            oddNum += 2;
        }
        return __gcd(evenSum, oddSum);
    }
};