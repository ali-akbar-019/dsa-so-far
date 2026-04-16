# 📋 DSA COMMENT TEMPLATE & IMPLEMENTATION GUIDE

**Usage:** Use this template for adding detailed comments to any DSA problem file.

---

## ✅ STANDARD COMMENT STRUCTURE

Every enhanced file follows this structure:

### 1. **Header Block** (Top of file)

```cpp
/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: [Problem Name] (LeetCode #XXX) [Optional: - DIFFICULTY/PATTERN]
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  [Clear description of what needs to be solved]
  [What are inputs? What are expected outputs?]
  Example: [input] → [output]

ALGORITHM: [Name of the approach]
  KEY IDEA: [Most important concept/insight in 1-2 sentences]

  APPROACH:
  [Step-by-step explanation of the algorithm]
  [Why this approach works]

TIME COMPLEXITY: O(...) - [brief explanation]
SPACE COMPLEXITY: O(...) - [brief explanation]

KEY INSIGHT: [Important observation, potential pitfall, or optimization]

═══════════════════════════════════════════════════════════════════════
*/
```

### 2. **Solution Method** (Inside Solution class)

```cpp
class Solution {
public:
    // [1-line function description]
    ReturnType methodName(ParameterType param) {

        // STEP 1: [First major operation]
        // [Explanation of what this step does]
        // [Variable declarations/initializations]

        // STEP 2: [Second major operation]
        // [Detailed explanation]
        // [For complex operations: explain each line]

        // STEP 3: [Process/calculate main result]
        // [Some explanation]

        // STEP 4: [Finalize/return result]
        return result;
    }
};
```

---

## 📚 CATEGORY-SPECIFIC TEMPLATES

### 1. **ARRAY PROBLEMS**

```cpp
/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: [Array Problem Name] (LeetCode #XXX)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given array of integers, [specific task].
  Example: [arr] → [result]

ALGORITHM: [Binary Search / Sorting / Hashing / Two Pointers]
  This problem can be broken into:
  1. [Preprocessing step - sort, count, etc.]
  2. [Core logic step]
  3. [Optimization or special handling]

TIME COMPLEXITY: O(...)
SPACE COMPLEXITY: O(...)

═══════════════════════════════════════════════════════════════════════
*/
class Solution {
public:
    ReturnType solve(vector<int> &nums) {
        // Initialize result
        int n = nums.size();

        // OPTIONAL: Sort if needed
        sort(nums.begin(), nums.end());

        // Main logic
        for (int i = 0; i < n; i++) {
            // Process each element
        }

        return result;
    }
};
```

### 2. **LINKED LIST PROBLEMS**

```cpp
/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: [Linked List Operation] (LeetCode #XXX)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given a linked list, [specific operation].
  Example: [Input list] → [Output list]

ALGORITHM: [Iterative / Recursive / Two-Pointer / Multiple Pass]
  For linked lists:
  - Consider edge cases: empty list, single node
  - Usually requires traversing and modifying pointers
  - May need dummy node for simplification

TIME COMPLEXITY: O(n) - n = number of nodes
SPACE COMPLEXITY: O(h) - h = height/recursion depth (or O(1) iterative)

═══════════════════════════════════════════════════════════════════════
*/
class Solution {
public:
    ListNode *solve(ListNode *head) {
        // Edge cases
        if (!head || !head->next) return head;

        // STEP 1: Traverse and collect/modify
        ListNode *curr = head;
        while (curr) {
            // Modify pointers or collect info
            curr = curr->next;
        }

        // STEP 2: Construct or return result
        return result;
    }
};
```

### 3. **TREE/BINARY TREE PROBLEMS**

```cpp
/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: [Tree Operation] (LeetCode #XXX)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given binary tree, [specific task].
  Example: [Input tree] → [Output]

ALGORITHM: [DFS / BFS / Post-order / In-order / Pre-order / Level-order]
  TRAVERSAL ORDERS:
  - Pre-order: Process node, then left, then right (Node-Left-Right)
  - In-order: Process left, then node, then right (Left-Node-Right)
  - Post-order: Process left, then right, then node (Left-Right-Node)
  - Level-order: BFS layer by layer

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(h) - h = height, O(n) worst case skewed tree

═══════════════════════════════════════════════════════════════════════
*/
class Solution {
public:
    ReturnType solve(TreeNode *root) {
        // Base case
        if (!root) return base_case;

        // STEP 1: Process left subtree
        auto left = solve(root->left);

        // STEP 2: Process right subtree
        auto right = solve(root->right);

        // STEP 3: Process current node and combine results
        return combine(left, right, root->val);
    }
};
```

### 4. **STACK PROBLEMS**

```cpp
/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: [Stack/Monotonic Stack Problem] (LeetCode #XXX)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  [Problem description]
  Example: [input] → [output]

ALGORITHM: [Monotonic Stack / Standard Stack / Min Stack]
  Stack problems often involve:
  - Matching pairs (parentheses, brackets)
  - Finding next/previous greater/smaller element
  - Expression evaluation

  Monotonic Stack: Maintain elements in order (increasing/decreasing)
  - Pop elements not satisfying the monotonic property
  - Current element relates to what's being popped

TIME COMPLEXITY: O(n) - each element pushed/popped once
SPACE COMPLEXITY: O(n) - stack storage

═══════════════════════════════════════════════════════════════════════
*/
class Solution {
public:
    ReturnType solve(vector<int> &arr) {
        stack<int/pair> st;
        vector<int> result(arr.size());

        // Process from right to left (usually for "next" problems)
        for (int i = arr.size() - 1; i >= 0; i--) {
            // Pop to maintain monotonic property
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // Process result using stack top
            if (!st.empty()) {
                result[i] = /*calculation*/;
            }

            // Push current element
            st.push(arr[i]);
        }

        return result;
    }
};
```

### 5. **STRING PROBLEMS**

```cpp
/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: [String Manipulation] (LeetCode #XXX)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given a string, [specific task].
  Example: "[input]" → "[output]"

ALGORITHM: [Hashing / Two-Pointer / Sliding Window / Pattern Matching]
  String problems often use:
  - HashMap for character counting
  - Two pointers for comparison/matching
  - Sliding window for substrings
  - Recursion for permutations/combinations

TIME COMPLEXITY: O(...)
SPACE COMPLEXITY: O(...)

═══════════════════════════════════════════════════════════════════════
*/
class Solution {
public:
    ReturnType solve(string s) {
        // OPTION 1: Character frequency counting
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // OPTION 2: Two-pointer approach
        int left = 0, right = s.size() - 1;
        while (left < right) {
            // Process/compare
            left++;
            right--;
        }

        return result;
    }
};
```

### 6. **2D ARRAY / MATRIX PROBLEMS**

```cpp
/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: [Matrix Operation] (LeetCode #XXX)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given m x n matrix, [specific task].
  Example: [matrix] → [result]

ALGORITHM: [Boundary Shrinking / Spiral / DFS / BFS / Binary Search]
  Matrix operations often involve:
  - Traversing in specific patterns (spiral, diagonal, etc.)
  - Boundary handling (edges, corners)
  - 2D coordinate transformations
  - Row-wise or column-wise operations

TIME COMPLEXITY: O(m*n)
SPACE COMPLEXITY: O(1) or O(m*n) depending on approach

═══════════════════════════════════════════════════════════════════════
*/
class Solution {
public:
    ReturnType solve(vector<vector<int>> &matrix) {
        int m = matrix.size();    // rows
        int n = matrix[0].size(); // columns

        // Iterate with proper boundary checks
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Process matrix[i][j]
            }
        }

        return result;
    }
};
```

---

## 🎯 QUICK TIPS FOR WRITING COMMENTS

### ✅ DO:

- Explain the **WHY**, not just the **WHAT**
- Use clear variable names in comments
- Include concrete examples where helpful
- Highlight edge cases and boundary conditions
- Mention time/space complexity implications
- Explain non-obvious algorithmic choices

### ❌ DON'T:

- Comment every line of code (that's code smell)
- State obvious things: `i++; // increment i`
- Use unclear abbreviations
- Write comments that repeat variable names
- Forget to explain complex logic blocks

### 🔍 GOOD COMMENT EXAMPLE:

```cpp
// STEP 2: Process right subtree ONLY if left wasn't NULL
// Why? We need both sides to have solutions for root to be LCA
root->right = solve(root->left, p, q);
```

### ❌ BAD COMMENT EXAMPLE:

```cpp
// Solve right
root->right = solve(root->left, p, q); // This line solves the right
```

---

## 📑 CHECKLIST FOR EACH FILE

Before marking a file as "enhanced", ensure:

- [ ] Problem statement clearly explains what's being solved
- [ ] Algorithm name and approach documented
- [ ] Time complexity explained with reasoning
- [ ] Space complexity explained with reasoning
- [ ] Key insights highlighted
- [ ] Code has step-by-step comments for complex parts
- [ ] Variable names are clear in comments
- [ ] Edge cases mentioned where relevant
- [ ] Alternative approaches documented (if any)
- [ ] Example walkthrough provided (for complex problems)

---

## 🚀 NEXT STEPS

1. **Pick a file** from the "TODO" list in the main summary document
2. **Read the problem** (from filename and comments)
3. **Understand the algorithm** by reading the code
4. **Apply this template**:
   - Add header block with problem statement and algorithm explanation
   - Add step-by-step comments in the solution
   - Include complexity analysis
   - Highlight key insights
5. **Verify completeness** using the checklist above
6. **Mark as COMPLETE** ✅ in the summary document

---

## 📚 REFERENCE - COMPLEXITY CHEAT SHEET

| Operation     | Time       | Space | When to Use           |
| ------------- | ---------- | ----- | --------------------- |
| Single pass   | O(n)       | O(1)  | Arrays, strings       |
| Sorting       | O(n log n) | O(1)  | Need order            |
| HashMap       | O(n) avg   | O(n)  | Frequency, lookup     |
| Stack/Queue   | O(n)       | O(n)  | Next/prev element     |
| BFS           | O(V+E)     | O(V)  | Shortest path         |
| DFS           | O(V+E)     | O(h)  | Tree traversal        |
| DP            | O(n²)      | O(n²) | Optimization problems |
| Binary Search | O(log n)   | O(1)  | Sorted data           |

---

**Total Files Completed:** 15  
**Categories Covered:** 5 (Binary Tree, Arrays, Linked List, Stack, Strings)  
**Template Pattern:** Standardized and reusable across all categories
