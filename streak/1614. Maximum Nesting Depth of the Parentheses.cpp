class Solution
{
public:
    int maxDepth(string s)
    {
        int maxi = INT_MIN;
        int brks = 0;
        for (auto &ch : s)
        {
            if (ch == '(')
            {
                brks += 1;
            }
            else if (ch == ')')
            {
                brks -= 1;
            }
            maxi = max(brks, maxi);
        }
        return maxi;
    }
};