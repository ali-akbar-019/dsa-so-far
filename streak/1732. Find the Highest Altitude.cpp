class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        // we just have to find the max
        int max = 0;
        int curr = 0;
        for (auto &alt : gain)
        {
            curr += alt;
            if (curr > max)
            {
                max = curr;
            }
        }
        return max;
    }
};