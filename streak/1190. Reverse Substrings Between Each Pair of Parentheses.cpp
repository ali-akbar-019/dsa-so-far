class Solution
{
public:
    string reverseParentheses(string s)
    {
        // open bracket index
        stack<int> openBracketIndex;
        // maping of the open bracket and the close bracket
        int n = s.length();
        vector<int> bracketsMaping(n);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                openBracketIndex.push(i);
            }
            else if (s[i] == ')')
            {
                int j = openBracketIndex.top();
                openBracketIndex.pop();
                bracketsMaping[i] = j;
                bracketsMaping[j] = i;
            }
        }
        //
        // ab result me daalo
        string result = "";
        int flag = 1;
        for (int i = 0; i < n; i += flag)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                i = bracketsMaping[i]; // maping ha is me open se close and close se open
                flag *= -1;
            }
            else
            {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};