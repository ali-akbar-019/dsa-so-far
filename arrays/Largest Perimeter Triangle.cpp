/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Largest Perimeter Triangle (LeetCode 976)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given array of integers representing potential sides, find three sides that
  form a valid triangle with MAXIMUM PERIMETER.
  Triangle inequality: a + b > c (sum of any two sides > third side)
  Return perimeter of triangle, or 0 if no valid triangle exists.

ALGORITHM: Greedy Sorting with Early Termination
  STEP 1: Sort array in ascending order
  STEP 2: Start from largest three elements (end of sorted array)
  STEP 3: For three consecutive elements a ≤ b ≤ c:
          - Only need to check: a + b > c (other conditions auto-satisfied)
  STEP 4: First valid triangle found has maximum perimeter (due to sorting)
  STEP 5: Return sum if found, else 0

TIME COMPLEXITY: O(n log n) - dominated by sorting
SPACE COMPLEXITY: O(1) - only using constant extra space

KEY INSIGHT: Greedy works because we want largest perimeter.
After sorting, checking from end ensures we find answer quickly.

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        // STEP 1: Sort array in ascending order
        sort(nums.begin(), nums.end());

        // STEP 2: Start checking from largest three elements (from the end)
        int n = nums.size();

        // Check triplets starting from the largest
        for (int i = n - 3; i >= 0; i--)
        {
            // Three sides: nums[i] ≤ nums[i+1] ≤ nums[i+2]
            // For triangle: a + b > c
            // Since sorted: nums[i] ≤ nums[i+1], so only need: nums[i] + nums[i+1] > nums[i+2]
            if (nums[i] + nums[i + 1] > nums[i + 2])
            {
                // Valid triangle found - first is largest due to sorting
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        // STEP 3: No valid triangle possible
        return 0;
    }
};