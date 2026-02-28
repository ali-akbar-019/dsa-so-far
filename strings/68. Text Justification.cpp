class Solution
{
public:
    string getLine(vector<string> &words, int i, int j, int spacesBetweenWords, int extraSpaces, int lettersCount, int maxWidth)
    {
        string line;
        for (int k = i; k < j; k++)
        {
            line += words[k];
            int sbw = spacesBetweenWords;
            // we dont have to give space after last word
            if (k == j - 1)
                continue;
            // now spaces
            while (sbw--)
            {
                line += " ";
            }
            if (extraSpaces)
            {
                line += " ";
                extraSpaces--;
            }
        }
        int remSpaces = maxWidth - line.size();
        while (remSpaces > 0)
        {
            line += " ";
            remSpaces--;
        }
        return line;
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int n = words.size();
        vector<string> result;
        int i = 0;
        while (i < n)
        {
            int lettersCount = words[i].length();
            int spaces = 0;
            int j = i + 1;
            while (j < n && words[j].length() + 1 + spaces + lettersCount <= maxWidth)
            {
                lettersCount += words[j].length();
                spaces++;
                j++;
            }
            // ab extra spaces and kitni spaces hni chahei wo deko
            int rem = maxWidth - lettersCount;
            int spacesBetweenWords = spaces <= 0 ? 0 : rem / spaces;
            int extraSpaces = spaces <= 0 ? 0 : rem % spaces;
            if (j == n)
            {
                // means last line
                spacesBetweenWords = 1;
                extraSpaces = 0;
            }
            result.push_back(getLine(words, i, j, spacesBetweenWords, extraSpaces, lettersCount, maxWidth));
            i = j;
        }
        return result;
    }
};