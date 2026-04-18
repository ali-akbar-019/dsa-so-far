class Solution
{
public:
    int revNum(int num)
    {
        int x = 0;
        while (num > 0)
        {
            x = x * 10 + num % 10;
            num = num / 10;
        }
        return x;
    }
    int mirrorDistance(int n)
    {
        int rev = revNum(n);
        int ans = abs(n - rev);
        return ans;
    }
};