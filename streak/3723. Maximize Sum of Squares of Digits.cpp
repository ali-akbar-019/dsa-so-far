class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {
        if (sum > num * 9)
        {
            return "";
        }
        // 9 9 se bharne ka try karo
        int nines = sum / 9;
        int rem = sum % 9;

        string result(nines, '9');
        if (rem > 0)
        {
            result.push_back(rem + '0');
        }
        // baqi jo bacha waha pe zero dal do
        result.append(num - result.size(), '0');
        return result;
    }
};