class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        int count = 0;
        for (int i = left; i <= right; i++)
        {
            int num = i;
            int countOfOnes = __builtin_popcount(num); // builtin function to find hten umber of ones
            if (isPrime(countOfOnes))
            {
                count++;
            }
        }
        return count;
    }
    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        for (int i = 2; i * i <= n; i++)
        {
            if ((n % i) == 0)
            {
                return false;
            }
        }
        return true;
    }
};