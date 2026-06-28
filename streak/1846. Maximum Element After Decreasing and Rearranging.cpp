class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int n = arr.size();
        // sort kar do
        sort(begin(arr), end(arr));
        // ab bas check karte raho k greater than one aya to bas next index pe prev value + 1 dal do
        int maxEl = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                arr[i] = 1; // 1 bana do
            }
            else if (abs(arr[i] - arr[i - 1]) > 1)
            {
                arr[i] = arr[i - 1] + 1;
            }
            maxEl = max(maxEl, arr[i]);
        }
        return maxEl;
    }
};