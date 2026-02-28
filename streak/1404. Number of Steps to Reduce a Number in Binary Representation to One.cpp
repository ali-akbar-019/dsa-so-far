class Solution
{
public:
    int numSteps(string s)
    {
        int carry = 0;
        int operations = 0;
        int n = s.length();
        for (int i = n - 1; i >= 1; i--)
        {
            // bcz first one is always hthe 1, and depending on the last we find that weather
            // its a even or odd numbr
            // for even we have one operations
            // for odd we have two operations
            if ((s[i] - '0' + carry) % 2 == 0)
            {
                // means even so
                operations += 1;
            }
            else
            {
                operations += 2;
                carry = 1;
            }
        }
        return operations + carry;
    }
};