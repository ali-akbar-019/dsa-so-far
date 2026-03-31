class Solution
{
public:
    bool isSame(string &word, string str2, int i, int m)
    {
        for (int j = 0; j < m; j++)
        {
            if (word[i + j] != str2[j])
            {
                return false;
            }
        }
        return true;
    }
    string generateString(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();
        int N = n + m - 1;
        string word(N, '$');
        // first of all lets check for the T if yes then just put in the word
        for (int i = 0; i < n; i++)
        {
            if (str1[i] == 'T')
            {
                // we have to place in the word
                int k = i;
                for (int j = 0; j < m; j++)
                {
                    // dalne se pehle deko k kahi clash to nai kr rha
                    if (word[k] != '$' && word[k] != str2[j])
                    {
                        return "";
                    }
                    word[k++] = str2[j];
                }
            }
        }
        vector<bool> canChange(N, 0);
        // ab fill karo a ko
        for (int i = 0; i < N; i++)
        {

            if (word[i] == '$')
            {
                word[i] = 'a';
                canChange[i] = true;
            }
        }
        //
        // validate the F
        for (int i = 0; i < n; i++)
        {
            if (str1[i] == 'F')
            {
                // now ab check karo k kahi same to nahi ban rahe
                int changed = false;
                if (isSame(word, str2, i, m))
                {
                    // ab tm ise change krne ka try karo
                    for (int k = i + m - 1; k >= i; k--)
                    {
                        if (canChange[k])
                        {
                            word[k] = 'b';
                            canChange[k] = false;
                            changed = true;
                            break;
                        }
                    }
                    if (!changed)
                    {
                        return "";
                    }
                }
            }
        }
        return word;
    }
};