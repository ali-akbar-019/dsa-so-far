class Solution
{
public:
    int count1s(int num)
    {
        int count = 0;
        while (num > 0)
        {
            if (num & 1)
            {
                count++;
            }
            num >>= 1;
        }
        return count;
    }

    vector<int> sortByBits(vector<int> &arr)
    {
        auto lambda = [this](int a, int b)
        {
            int countA = count1s(a);
            int countB = count1s(b);
            if (countA == countB)
            {
                return a < b;
            }
            return countA < countB;
        };
        sort(begin(arr), end(arr), lambda);
        return arr;
    }
};