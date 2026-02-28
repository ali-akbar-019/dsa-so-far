class Solution
{
public:
    bool isPalindrome(string s)
    {
        string clearText = "";

        for (char c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                clearText += c;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                clearText += (c - 'A' + 'a');
            }
            else if (c >= '0' && c <= '9')
            {
                clearText += c;
            }
        }

        int start = 0, end = clearText.size() - 1;
        while (start < end)
        {
            if (clearText[start] != clearText[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};