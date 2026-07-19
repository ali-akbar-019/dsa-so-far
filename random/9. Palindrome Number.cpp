class Solution
{
public:
    bool isPalindrome(int x)
    {
        //
        if (x < 0)
            return false;
        vector<int> num;
        while (x != 0)
        {
            int dig = x % 10;
            num.push_back(dig);
            x /= 10;
        }
        //
        int l = 0;
        int r = num.size() - 1;
        while (l < r)
        {
            if (num[l] != num[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};