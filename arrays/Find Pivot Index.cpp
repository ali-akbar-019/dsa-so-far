/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Find Pivot Index (LeetCode 1991)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given an array nums, find pivot index where sum of left elements = sum of right elements.
  Example: [1,7,3,6,5,6] → pivot is 3 (left=[1,7,3]=11, right=[6,5]=11)

ALGORITHM: Two-Pass Prefix Sum
  PASS 1: Calculate total sum of all elements
  PASS 2: Iterate through array checking if leftSum == rightSum
          - leftSum = sum of elements before current index
          - rightSum = total - leftSum - current_element
          - If equal, return the index

TIME COMPLEXITY: O(n) - two passes through array
SPACE COMPLEXITY: O(1) - only using constant extra space

KEY INSIGHT: We don't need to calculate right sum from scratch each time.
We can derive it from totalSum - leftSum - current_element.

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        // STEP 1: Calculate total sum of all elements
        int totalSum = 0;
        for (int &num : nums)
        {
            totalSum += num;
        }

        // STEP 2: Iterate through array checking for pivot
        int leftSum = 0; // cs = currentSum from left side
        for (int i = 0; i < nums.size(); i++)
        {
            // Calculate right sum: total - left - current
            int rightSum = totalSum - leftSum - nums[i];

            // If left sum equals right sum, we found the pivot
            if (leftSum == rightSum)
            {
                return i; // Found pivot index
            }

            // Add current element to left sum for next iteration
            leftSum += nums[i];
        }

        // No pivot found
        return -1;
    }
};