class Solution
{
public:
    int Count(long curr, long next, int n)
    {
        // n is the limit
        int count = 0;
        while (curr <= n)
        {
            count += next - curr;
            curr = curr * 10;
            next = next * 10;
            next = min(next, (long)n + 1); // cz next ki max value n + 1 ho sakti
        }
        return count;
    }
    int findKthNumber(int n, int k)
    {
        int curr = 1;
        // we took one number so now
        k -= 1;
        //
        while (k > 0)
        {
            //
            int count = Count(curr, curr + 1, n);
            if (count <= k)
            {
                k -= count; // aage jao .
                curr++;     // next prefix me jao
            }
            else
            {
                // curr me hi ha bas aik deep jao
                curr = curr * 10;
                k -= 1; // cz aik or check kar leya na
            }
        }
        return curr;
    }
};
// TC = O(log10n)^2 this is the number of digits
//  SC = O(log10n) // no.of digits