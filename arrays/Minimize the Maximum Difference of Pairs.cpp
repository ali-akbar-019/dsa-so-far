/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Minimize the Maximum Difference of Pairs (LeetCode 1877)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given array nums and integer p, select p pairs minimizing the MAXIMUM difference
  within any pair. Each element used at most once.
  Example: nums = [10,1,2,7,1,3], p = 2 → pairs could be (1,2), (1,3) → max = 1

ALGORITHM: Binary Search + Greedy Validation
  KEY INSIGHT: Use binary search on the answer (the maximum difference).

  APPROACH:
  1. Sort array
  2. Binary search on range [0, max-min]
  3. For each mid value, check if we can form p pairs with max_diff ≤ mid:
     - Use greedy: pair consecutive elements in sorted array
     - If they differ ≤ mid, pair them and skip both
     - Count pairs formed
     - If count ≥ p, this mid works, try smaller

TIME COMPLEXITY: O(n log n + n log(max-min))
SPACE COMPLEXITY: O(1) excluding output

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // Check if we can form p pairs with max difference ≤ maxDiff
    bool isValid(vector<int> &nums, int maxDiff, int p)
    {
        int pairsCount = 0;
        int i = 0;
        int n = nums.size();

        // Greedy: pair consecutive elements in sorted array
        while (i < n - 1)
        {
            // If consecutive elements differ ≤ maxDiff, pair them
            if ((nums[i + 1] - nums[i]) <= maxDiff)
            {
                pairsCount++; // Counted a pair
                i += 2;       // Skip both (used)
            }
            else
            {
                i++; // Try next element
            }
        }

        return pairsCount >= p;
    }

    int minimizeMax(vector<int> &nums, int p)
    {
        // STEP 1: Sort array
        sort(begin(nums), end(nums));

        // STEP 2: Binary search on the answer
        int n = nums.size();
        int left = 0;                      // Minimum possible max difference
        int right = nums[n - 1] - nums[0]; // Maximum possible gap
        int result = 0;

        // Find minimum possible maximum difference
        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (isValid(nums, mid, p))
            {
                // Can form p pairs with max diff ≤ mid
                // Try smaller maximum difference
                result = mid;
                right = mid - 1;
            }
            else
            {
                // Cannot form p pairs with this max diff
                // Need larger maximum difference
                left = mid + 1;
            }
        }

        return result;
    }
};