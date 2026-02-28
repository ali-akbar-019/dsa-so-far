class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<char> alphabetsArray(26, 0);
        for (int i = 0; i < sentence.size(); i++)
        {
            int ch = sentence[i] - 'a';
            alphabetsArray[ch]++;
        }
        //
        for (int i = 0; i < 26; i++)
        {
            if (alphabetsArray[i] == 0)
            {
                return false;
            }
        }
        return true;
    }
};