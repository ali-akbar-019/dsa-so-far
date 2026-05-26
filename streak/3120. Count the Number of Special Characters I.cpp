// bad code that i wrote
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        // simplest approach
        int n = word.size();
        unordered_set<int> st;
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            // agar bara ha to check karo k is k leey chota present ha
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
                // means we have the capital
                // check if the small present
                if (st.find(word[i] - 'A' + 'a') != st.end())
                {
                    result += 1; // means we have one
                    // now remove it from the map
                    st.erase(word[i] - 'A' + 'a');
                }
            }
            else
            {
                // we have a small character
                if (st.find(word[i]) == st.end())
                {
                    // then add so that we can avoid the duplicates
                    st.insert(word[i]);
                }
            }
        }
        return result;
    }
};
// correct code that i wrote
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int n = word.size();
        unordered_set<char> lowerseen;
        unordered_set<char> uppercounted;
        int result = 0;
        for (auto &ch : word)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                lowerseen.insert(ch);
            }
            else
            {
                // we have upper
                // check we have not already counted it
                char lower = ch - 'A' + 'a';
                if (lowerseen.count(lower) && !uppercounted.count(lower))
                {
                    result += 1;
                    // ad to the upper counter
                    uppercounted.insert(lower);
                }
            }
        }
        return result;
    }
};

//
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {

        unordered_set<char> lower;
        unordered_set<char> upper;

        // store lowercase and uppercase letters separately
        for (char ch : word)
        {

            if (ch >= 'a' && ch <= 'z')
            {
                lower.insert(ch);
            }
            else
            {
                upper.insert(ch);
            }
        }

        int result = 0;

        // check which characters exist in both forms
        for (char ch = 'a'; ch <= 'z'; ch++)
        {

            char upperChar = ch - 'a' + 'A';

            if (lower.count(ch) && upper.count(upperChar))
            {
                result++;
            }
        }

        return result;
    }
};

// 100% correct code
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {

        unordered_set<char> lower;
        unordered_set<char> upper;

        // store lowercase and uppercase letters separately
        for (char ch : word)
        {

            if (ch >= 'a' && ch <= 'z')
            {
                lower.insert(ch);
            }
            else
            {
                upper.insert(ch);
            }
        }

        int result = 0;

        // check which characters exist in both forms
        for (char ch = 'a'; ch <= 'z'; ch++)
        {

            char upperChar = ch - 'a' + 'A';

            if (lower.count(ch) && upper.count(upperChar))
            {
                result++;
            }
        }

        return result;
    }
};
