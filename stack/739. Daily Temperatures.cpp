/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Daily Temperatures (LeetCode 739) - MONOTONIC STACK PATTERN
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given array of daily temperatures, for each day find days until warmer temp.
  Example: [73,74,75,71,69,72,76,73] → [1,1,4,2,1,1,0,0]

ALGORITHM: Monotonic Decreasing Stack (Right-to-Left)
  KEY INSIGHT: Maintain stack of indices in DECREASING temperature order.
  When processing right to left, stack top is next warmer day.

  APPROACH:
  1. Traverse from RIGHT to LEFT (we need future temps)
  2. Pop indices with temp ≤ current (not our next warmer)
  3. If stack not empty, top index is next warmer day
  4. Push current index to maintain decreasing order

TIME COMPLEXITY: O(n) - each element pushed/popped once
SPACE COMPLEXITY: O(n) - stack storage

KEY INSIGHT: Monotonic stack solves "next greater element" efficiently.

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // Find days until warmer for each day using monotonic stack
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st; // Stack stores indices in decreasing temp order
        int n = temperatures.size();
        vector<int> result(n, 0); // Result: 0 means no warmer day found

        // STEP 1: Process temperatures RIGHT to LEFT
        // Why right? We need to look into the future
        for (int i = n - 1; i >= 0; i--)
        {
            // STEP 2: Remove indices with temp ≤ current from stack
            // They cannot be the next warmer day
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }

            // STEP 3: If stack not empty, top is next warmer day
            if (!st.empty())
            {
                result[i] = st.top() - i; // Distance = future_index - current_index
            }
            // else result[i] stays 0 (no warmer day)

            // STEP 4: Push current index to maintain decreasing order
            st.push(i);
        }

        return result;
    }
};