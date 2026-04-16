/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Add to Array-Form of Integer (LeetCode 989)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given array `num` representing a number and integer `k`, return their sum as array.
  Example: num = [1,2,0,0], k = 34 → [1,2,3,4] (1200 + 34 = 1234)

ALGORITHM: Reverse Addition with Carry
  - Process from RIGHT to LEFT (similar to manual addition)
  - Start from last digit of array (most significant in last position)
  - Add corresponding digit from k and handle carry
  - Extract last digit (mod 10) and add to result
  - Move to next digit and divide k by 10
  - Continue until both array and k are exhausted
  - Reverse result since we built it backwards

TIME COMPLEXITY: O(n) where n = max(len(num), len(k converted to string))
SPACE COMPLEXITY: O(1) excluding output array

KEY INSIGHT: Build result in reverse order, then reverse once at end.

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int n = num.size();
        int i = n - 1; // Start from last element (rightmost)
        vector<int> result;

        // STEP 1: Process array and k from right to left
        // Continue while we have array elements or remaining k
        while (i >= 0 || k > 0)
        {
            // Add current digit from array (if exists) to k
            if (i >= 0)
            {
                k += num[i]; // Add current digit to k
            }

            // Extract last digit and add to result
            // (We're building result in reverse order)
            result.push_back(k % 10);

            // Move to previous array element
            i--;

            // Remove the last digit from k (move to next digit)
            k /= 10;
        }

        // STEP 2: Reverse result since we built it backwards
        reverse(begin(result), end(result));

        return result;
    }
};