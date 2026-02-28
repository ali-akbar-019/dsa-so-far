class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        int n = s.length();
        long long size = 0;
        // first of all we haev to find the siez
        for (char &ch : s)
        {
            if (isdigit(ch))
            {
                size = size * (ch - '0'); // ab2 now here we will have 2 and we will get ans 4
            }
            else
            {
                size += 1; // for a b etc we just add one
            }
        }
        //
        // now lets check
        // we say that if k modulo size == 0 then we get ans at the last index
        for (int i = n - 1; i >= 0; i--)
        {
            k = k % size;
            char ch = s[i];
            if (k == 0 && isalpha(ch))
            {
                return string(1, ch);
            }
            // else we dont have k = 0 or we got s[i] as a digit
            if (isdigit(ch))
            {
                size = size / (ch - '0');
            }
            if (isalpha(ch))
            {
                size = size - 1;
            }
        }
        return "";
    }
};