/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Median of Two Sorted Arrays (LeetCode 4) - HARD
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given two sorted arrays nums1 and nums2 of sizes m and n,
  find the MEDIAN of the combined sorted array.
  Example: nums1 = [1,3], nums2 = [2] → median = 2.0

ALGORITHM: Binary Search on Partition
  KEY INSIGHT: Instead of merging arrays, find correct partition point.

  PARTITION CONCEPT:
  - Divide combined array into equal halves: left_half and right_half
  - For even total size: median = (max(left) + min(right)) / 2
  - For odd total size: median = max(left)

  BINARY SEARCH APPROACH:
  1. Ensure nums1 is smaller array (optimization)
  2. Binary search on partition index in nums1
  3. Calculate corresponding partition in nums2
  4. Check if partition is valid:
     - max(left_part) ≤ min(right_part) for both arrays
  5. When valid partition found, calculate median

TIME COMPLEXITY: O(log(min(m,n))) - binary search on smaller array
SPACE COMPLEXITY: O(1) - constant space

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Optimization: Ensure nums1 is the smaller array
        // This ensures binary search is on smaller array = fewer iterations
        if (n2 < n1)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Binary search will be on nums1
        int low = 0;   // Leftmost partition position in nums1
        int high = n1; // Rightmost partition position in nums1
        int totalLength = (n1 + n2);

        // Number of elements that should be in left half
        int leftCount = (n1 + n2 + 1) / 2;

        // STEP 1: Binary search for correct partition
        while (low <= high)
        {
            // Partition index in nums1 and nums2
            int mid1 = (low + high) >> 1; // Elements from nums1 in left half
            int mid2 = leftCount - mid1;  // Elements from nums2 in left half

            // Boundary values around partition points
            int left1 = INT_MIN, left2 = INT_MIN;   // Max of left halves
            int right1 = INT_MAX, right2 = INT_MAX; // Min of right halves

            // Get left boundary value from nums1 (if exists)
            if (mid1 < n1)
                right1 = nums1[mid1];
            if (mid1 - 1 >= 0)
                left1 = nums1[mid1 - 1];

            // Get left boundary value from nums2 (if exists)
            if (mid2 < n2)
                right2 = nums2[mid2];
            if (mid2 - 1 >= 0)
                left2 = nums2[mid2 - 1];

            // STEP 2: Check if partition is valid
            // Valid if: max(left) ≤ min(right) for both arrays
            if (left1 <= right2 && left2 <= right1)
            {
                // STEP 3: Calculate and return median

                // Case 1: Total elements is ODD
                if (totalLength % 2 == 1)
                {
                    return max(left1, left2);
                }
                // Case 2: Total elements is EVEN
                else
                {
                    return ((double)(max(left1, left2) + min(right1, right2))) / 2.0;
                }
            }
            // Partition too far right in nums1 (left1 > right2)
            // Move partition left
            else if (left1 > right2)
            {
                high = mid1 - 1;
            }
            // Partition too far left in nums1
            // Move partition right
            else
            {
                low = mid1 + 1;
            }
        }

        return 0; // Should never reach here for valid input
    }
};