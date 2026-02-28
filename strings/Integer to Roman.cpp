class Solution
{
public:
    vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> symb = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string intToRoman(int num)
    {
        string result = "";
        for (int i = 0; i < 13; i++)
        {
            int times = num / val[i];
            while (times--)
            {
                result += symb[i];
            }
            //
            num = num % val[i];
        }
        return result;
    }
};