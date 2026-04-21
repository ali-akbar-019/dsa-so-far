class Solution
{
public:
    vector<int> parent; // parent[i] = parent of index i

    // 🔍 Find the root (leader) of a node
    int findRoot(int index)
    {
        if (parent[index] == index)
            return index;

        // Path compression (make tree flat)
        return parent[index] = findRoot(parent[index]);
    }

    // 🔗 Connect two indices (put them in same group)
    void connect(int index1, int index2)
    {
        int root1 = findRoot(index1);
        int root2 = findRoot(index2);

        if (root1 != root2)
        {
            parent[root1] = root2;
        }
    }

    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();

        // 🟢 STEP 1: Initialize each index as its own parent
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        // 🟢 STEP 2: Build connected components
        // If we can swap (a, b), they belong to same group
        for (auto &pair : allowedSwaps)
        {
            int indexA = pair[0];
            int indexB = pair[1];
            connect(indexA, indexB);
        }

        // 🟢 STEP 3: Group all indices by their root
        unordered_map<int, vector<int>> groups;
        // key = root, value = all indices in that group

        for (int i = 0; i < n; i++)
        {
            int root = findRoot(i);
            groups[root].push_back(i);
        }

        int totalMismatch = 0;

        // 🟢 STEP 4: Process each group independently
        for (auto &groupEntry : groups)
        {

            vector<int> &indices = groupEntry.second;

            // Count frequency of values in source for this group
            unordered_map<int, int> valueCount;

            for (int idx : indices)
            {
                int value = source[idx];
                valueCount[value]++;
            }

            // Try to match target values using available source values
            for (int idx : indices)
            {
                int neededValue = target[idx];

                if (valueCount[neededValue] > 0)
                {
                    // We found a match → use it
                    valueCount[neededValue]--;
                }
                else
                {
                    // No matching value available → mismatch
                    totalMismatch++;
                }
            }
        }

        // 🟢 STEP 5: Return final answer
        return totalMismatch;
    }
};