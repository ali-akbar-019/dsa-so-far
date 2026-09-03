class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        int mini = *min_element(begin(nums1), end(nums1));
        if (mini % 2 != 0)
        {
            return true; // agar odd huwa fir sab k sab ko odd bana sakte ha ham like har even ko , cz even - odd
        }
        for (auto &num : nums1)
        {
            if (num % 2 != 0)
            {
                return false; // agar aik b odd mil gaya to even se odd nahi bana sakte ham
            }
        }
        return true;
    }
};