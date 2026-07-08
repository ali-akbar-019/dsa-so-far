class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        string num = "";
        long long temp = n;
        long long sum = 0;
        while (temp != 0)
        {
            int dig = temp % 10;
            if (dig != 0)
            {
                num = char(dig + '0') + num;

                sum += dig;
            }
            temp = temp / 10;
        }
        cout << "num: " << num << endl;
        cout << "sum: " << sum << endl;
        return stoi(num) * sum;
    }
};
// best method
class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        if (n == 0)
            return 0;
        long long places = 1;
        long long num = 0;
        long long sum = 0;
        while (n > 0)
        {
            int dig = n % 10;
            if (dig != 0)
            {
                num = num + (dig * places);
                places *= 10;
                sum += dig;
            }
            n = n / 10;
        }

        return num * sum;
    }
};