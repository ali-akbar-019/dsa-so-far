class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string answer;
        int n = words.size();
        for (auto &word : words)
        {
            //
            int sum = 0;
            for (int i = 0; i < word.length(); i++)
            {
                sum += weights[word[i] - 'a'];
            }
            //
            sum = sum % 26;
            // rev
            char ch = 'z';
            while (sum)
            {
                ch--;
                sum--;
            }
            answer += ch;
        }
        return answer;
    }
};