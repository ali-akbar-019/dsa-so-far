class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;

        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;

            while (freq[s[r]] > 2) {
                freq[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};