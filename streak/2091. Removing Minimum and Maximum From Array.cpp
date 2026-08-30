class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();
        int minElIdx = min_element(begin(nums), end(nums)) - begin(nums);
        int maxElIdx = max_element(begin(nums), end(nums)) - begin(nums);

        int left = min(minElIdx, maxElIdx);
        int right = max(minElIdx, maxElIdx);

        // answer k leye teen option ha
        // ya to aik left pe ho ga and aik right pe
        int leftAndRight = (left + 1) + (n - right);
        int bothAtLeft = right + 1;
        int bothAtRight = n - left;
        return min({leftAndRight, bothAtLeft, bothAtRight});
    }
};