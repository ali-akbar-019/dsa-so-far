/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Contains Duplicate II (LeetCode 219)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given array nums and integer k, check if two distinct indices i,j exist where:
  - nums[i] == nums[j] AND
  - abs(i - j) <= k
  Return true if condition met, false otherwise.

ALGORITHM: HashMap with Index Tracking
  - Use unordered_map to store last seen index of each element
  - For each element:
    1. Check if element exists in map AND distance is ≤ k
    2. If yes, return true (found duplicate within range)
    3. If no, update/insert element's index in map
  - If we finish without finding, return false

TIME COMPLEXITY: O(n) - single pass through array
SPACE COMPLEXITY: O(min(n, k)) - map stores at most (k+1) elements

KEY INSIGHT: We only need to track indices, not all occurrences.

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // Check if duplicate exists within distance k
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // HashMap to store most recent index of each element
        unordered_map<int, int> indexMap;

        // STEP 1: Iterate through array
        for (int i = 0; i < nums.size(); i++)
        {
            // STEP 2: Check if current element exists in map
            if ((indexMap.find(nums[i]) != indexMap.end()) &&
                (abs(indexMap[nums[i]] - i) <= k))
            {
                // Element found in map AND within distance k
                return true; // Duplicate within range found
            }
            else
            {
                // Element not found, or not within range
                // Update/insert current element's index
                indexMap[nums[i]] = i;
            }
        }

        // STEP 3: No duplicate within range found
        return false;
    }
};