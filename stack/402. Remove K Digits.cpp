class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.length();
        string result = ""; // it will act like a stack
        for (int i = 0; i < n; i++)
        {
            while (result.length() > 0 && result.back() > num[i] && k > 0)
            {
                // now pop
                result.pop_back();
                k--;
            }
            // else we have to add to the result
            if (result.length() > 0 || num[i] != '0')
            {
                result.push_back(num[i]);
            }
        }
        // now we gotta check if already sorted and k still the same then delete the first
        while (result.length() > 0 && k > 0)
        {
            result.pop_back();
            k--;
        }
        // now check if the result length is 0 then return "0" else return the output
        if (result.length() == 0)
        {
            return "0";
        }
        return result;
    }
};