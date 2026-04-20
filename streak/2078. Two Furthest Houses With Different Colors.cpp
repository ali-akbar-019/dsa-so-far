class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        // first ka end se check kar lo
        int ans = 0;
        int n = colors.size();
        for (int j = n - 1; j >= 0; j--)
        {
            if (colors[0] != colors[j])
            {
                ans = max(ans, j);
                break;
            }
        }
        //
        // end wale ka deko start sse
        for (int i = 0; i < n; i++)
        {
            if (colors[i] != colors[n - 1])
            {
                ans = max(ans, n - 1 - i);
                break;
            }
        }
        return ans;
    }
};