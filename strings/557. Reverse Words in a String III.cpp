class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s); // tolenizer.
        string token;
        string result;
        while (ss >> token)
        {
            reverse(begin(token), end(token));
            result += token + " ";
        }
        result.pop_back(); // remove the extra space
        return result;
    }
};