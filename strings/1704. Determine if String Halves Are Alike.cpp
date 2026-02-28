class Solution
{
public:
    bool isVowel(char &ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool halvesAreAlike(string s)
    {
        int countLeft = 0;
        int countRight = 0;
        int n = s.size();
        int i = 0;
        int j = n / 2;
        while (i < (n / 2) && j < n)
        {
            if (isVowel(s[i]))
            {
                countLeft++;
            }
            if (isVowel(s[j]))
            {
                countRight++;
            }
            i++;
            j++;
        }
        return countLeft == countRight ? true : false;
    }
};