class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        // lets try the counting sort technique in here
        // find the max
        int maxi = INT_MIN;
        for (auto &cost : costs)
        {
            if (cost > maxi)
            {
                maxi = cost;
            }
        }
        // make the counting array
        vector<int> countingArray(maxi + 1, 0);
        // fill the array
        for (auto &cost : costs)
        {
            countingArray[cost]++;
        }
        // now check
        int ans = 0;
        for (int i = 0; i < countingArray.size(); i++)
        {
            if (countingArray[i] == 0)
                continue; // dont check

            while (countingArray[i] > 0)
            {
                coins -= i;
                countingArray[i]--;
                if (coins < 0)
                {
                    return ans;
                }
                ans += 1;
            }
        }
        return ans;
    }
};