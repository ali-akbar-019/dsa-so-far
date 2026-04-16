/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Find Original Array From Doubled Array (LeetCode 2007)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given array `changed` where each element x from original array appears as x and 2*x.
  Reconstruct the original array. If impossible, return empty array.
  Example: [4,1,3,6] → [2,1,3] (original doubled: [2→4, 1→2, 3→6])

ALGORITHM: Greedy Matching with HashMap
  STEP 1: Check if array size is even (must have pairs)
  STEP 2: Store frequency of each element in HashMap
  STEP 3: Sort array to process smallest elements first (greedy)
  STEP 4: For each element, check if its double exists
          - If exists, add to answer and decrement both frequencies
          - If not exists, return empty (impossible)
  STEP 5: Return original array

TIME COMPLEXITY: O(n log n) - dominated by sorting
SPACE COMPLEXITY: O(n) - HashMap storage

KEY INSIGHT: Greedy approach works: always pair smallest available element
with its double. This minimizes conflicts.

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        // STEP 1: Check if array size is even (each original has 2 elements)
        int n = changed.size();
        if (n % 2 == 1)
        {
            return {}; // Impossible - odd sized array
        }

        // STEP 2: Store frequency of each element
        unordered_map<int, int> frequency;
        for (int &num : changed)
        {
            frequency[num]++;
        }

        // STEP 3: Sort array to process smallest elements first (greedy)
        sort(changed.begin(), changed.end());

        // Result array for original elements
        vector<int> result;

        // STEP 4: Process each element
        for (int &num : changed)
        {
            // If this element is already used (frequency = 0), skip it
            if (frequency[num] == 0)
            {
                continue;
            }

            // Check if double of this element exists
            int doubled = num * 2;

            // If double doesn't exist or already used, impossible
            if (frequency.find(doubled) == frequency.end() || frequency[doubled] == 0)
            {
                return {}; // Cannot form original array
            }

            // Add this element to original array
            result.push_back(num);

            // Decrement frequencies (mark as used)
            frequency[num]--;
            frequency[doubled]--;
        }

        return result;
    }
};