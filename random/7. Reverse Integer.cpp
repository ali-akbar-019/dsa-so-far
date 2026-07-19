class Solution
{
public:
    int reverse(int x)
    {
        // ll is not allowed
        int revNum = 0;
        //!=0 q k minus to hamesha zero se neche hi rahe ga na
        while (x != 0)
        {
            int dig = x % 10;
            // checks k ham range me ha k nahi
            // last safe for the max is 7
            if (revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && dig > 7))
                return 0;
            // last safe for the min is -8
            if (revNum < INT_MIN / 10 || (revNum == INT_MIN / 10 && dig < -8))
                return 0;
            revNum = revNum * 10 + dig;
            x /= 10;
        }
        return revNum;
    }
};