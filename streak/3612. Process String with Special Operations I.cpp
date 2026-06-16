class Solution
{
public:
    string processStr(string s)
    {
        // jo kaha gaya ha bas kar do
        string result = "";
        for (auto &ch : s)
        {
            if (ch == '*' && result != "")
            {
                result.pop_back();
            }
            else if (ch == '#')
            {
                result += result;
            }
            else if (ch == '%')
            {
                reverse(begin(result), end(result));
            }
            else if (ch != '*' && ch != '#' && ch != '%')
            {
                result.push_back(ch);
            }
        }
        return result;
    }
};