class Solution
{
public:
    string countAndSay(int n)
    {
        // we will use the recursion
        if (n == 1)
        {
            return "1";
        }
        // recursion call kar do baqi k leyee
        string say = countAndSay(n - 1);
        string result = "";
        // ab processing karo
        for (int i = 0; i < say.length(); i++)
        {
            //
            char ch = say[i];
            //
            int count = 1;
            // check the count of ch
            while (i < say.length() - 1 && ch == say[i + 1])
            {
                count++;
                i++;
            }
            // add to teh string
            result += to_string(count) + string(1, ch);
        }
        return result;
    }
};