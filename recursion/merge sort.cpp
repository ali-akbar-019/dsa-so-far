class Solution
{
public:
    vector<int> merge(vector<int> &arr1, vector<int> &arr2)
    {
        if (arr1.size() == 0)
        {
            return arr2;
        }
        if (arr2.size() == 0)
        {
            return arr1;
        }
        //
        // now make a new array
        int n = arr1.size();
        int m = arr2.size();
        vector<int> res(n + m);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                res[k++] = arr1[i++];
            }
            else
            {
                res[k++] = arr2[j++];
            }
        }
        //
        while (i < n)
        {
            res[k++] = arr1[i++];
        }
        while (j < m)
        {
            res[k++] = arr2[j++];
        }
        return res;
    }
    vector<int> mergeSort(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            return {nums[l]};
        }
        //
        int mid = (l + r) >> 1;
        vector<int> arr1 = mergeSort(nums, l, mid);
        vector<int> arr2 = mergeSort(nums, mid + 1, r);

        return merge(arr1, arr2);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        // we will use the merge sort here
        int n = nums.size();
        int s = 0;
        return mergeSort(nums, 0, n - 1);
    }
};