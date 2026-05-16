class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // use simple binary search on it
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[right])
            {
                left = mid + 1; // q k mid ko to discard kar deya ha na
            }
            else
            {
                right = mid; // q k mid b ho sakta ha yar min
            }
        }
        // left ya right dono hi same ko point kar rahe ho ge to return kar do kisi ko b
        return nums[left];
    }
};