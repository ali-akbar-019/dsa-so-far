/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: First Unique Character in a String (LeetCode 387)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given string, find index of first character that appears only once.
  If no such character exists, return -1.
  Example: "leetcode" → 0 (l unique), "loveleetcode" → 2 (v unique)

ALGORITHM: Two-Pass HashMap Frequency Counting
  PASS 1: Count frequency of each character using HashMap
  PASS 2: Find first character with frequency == 1

  APPROACH:
  1. Create HashMap to track character frequencies
  2. Iterate through string, increment count for each character
  3. Iterate again, return index of first char with count=1
  4. If none found, return -1

TIME COMPLEXITY: O(n) - two linear passes
SPACE COMPLEXITY: O(1) - at most 26 letters, constant space

KEY INSIGHT: HashMap makes this O(n) instead of O(n²) brute force.

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // Find index of first character that appears only once
    int firstUniqChar(string s)
    {
        // STEP 1: Count frequency of each character
        unordered_map<char, int> charFrequency;

        for (char c : s)
        {
            charFrequency[c]++; // Increment count for current character
        }

        // STEP 2: Find first character with frequency = 1 (unique)
        for (int i = 0; i < s.size(); i++)
        {
            if (charFrequency[s[i]] == 1)
            {
                return i; // Found first unique character
            }
        }

        // STEP 3: No unique character found
        return -1;
    }
};