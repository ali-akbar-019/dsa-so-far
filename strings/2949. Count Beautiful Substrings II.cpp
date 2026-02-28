class Solution
{
public:
#define ll long long
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long beautifulSubstrings(string s, int k)
    {
        ll n = s.size();
        unordered_map<ll, unordered_map<ll, ll>> mp;
        ll vowel = 0;
        ll consonent = 0;
        ll result = 0;
        mp[0][0] = 1; /// 0->0->1
        for (char &ch : s)
        {
            if (isVowel(ch))
            {
                vowel++;
            }
            else
            {
                consonent++;
            }
            // check the map
            ll pSum = vowel - consonent;
            // check the map
            for (auto &[prevVowel, count] : mp[pSum])
            {
                if ((vowel % k - prevVowel) * (vowel % k - prevVowel) % k == 0)
                {
                    result += count;
                }
            }
            mp[pSum][vowel % k]++;
        }
        return result;
    }
};