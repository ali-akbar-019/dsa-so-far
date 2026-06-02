class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        // sort in the decending order
        sort(begin(cost), end(cost), greater<int>());
        //
        int total = 0;
        for (int i = 0; i < cost.size(); i++)
        {
            if (i % 3 != 2)
            {
                total += cost[i];
            }
        }
        return total;
    }
};