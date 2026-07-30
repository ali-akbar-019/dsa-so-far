class Solution
{
public:
    int minimumPushes(string word)
    {
        // freq store karo
        // and kitne press lage ge wo is formula se nikel ga freq * i/8 + 1
        vector<int> freqs(26, 0);
        for (auto &w : word)
        {
            freqs[w - 'a']++;
        }
        // decending order pe sor kar do
        sort(begin(freqs), end(freqs), greater<int>());
        // ab formula
        int result = 0;
        for (int i = 0; i < 26; i++)
        {
            // 0 wale to zero ho jaye ge na
            int freq = freqs[i];
            result += freq * ((i / 8) + 1);
        }
        return result;
    }
};