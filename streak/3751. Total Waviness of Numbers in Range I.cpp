class Solution
{
public:
    int findWaviness(int num)
    {
        string str = to_string(num);
        if (str.length() < 3)
        {
            return 0;
        }
        // else check
        int total = 0;
        for (int i = 1; i <= str.length() - 2; i++)
        {
            int n = str[i];
            int n_1 = str[i - 1];
            int n_2 = str[i + 1];
            if (n > n_1 && n > n_2)
            {
                total += 1;
            }
            if (n < n_1 && n < n_2)
            {
                total += 1;
            }
        }
        return total;
    }
    int totalWaviness(int num1, int num2)
    {
        int waviness = 0;
        for (int num = num1; num <= num2; num++)
        {
            waviness += findWaviness(num);
        }
        return waviness;
    }
};