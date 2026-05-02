class Solution
{
public:
    int rotatedDigits(int n)
    {
        vector<int> vec(n + 1, -1);

        int base[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
        for (int i = 0; i <= min(n, 9); i++)
        {
            vec[i] = base[i];
        }

        int good_num = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i < 10)
            {
                if (vec[i] == 1)
                    good_num++;
                continue;
            }

            int quot = i / 10;
            int rem = i % 10;

            if (vec[quot] == -1 || vec[rem] == -1)
            {
                vec[i] = -1;
            }
            else if (vec[quot] == 1 || vec[rem] == 1)
            {
                vec[i] = 1;
                good_num++;
            }
            else
            {
                vec[i] = 0;
            }
        }

        return good_num;
    }
};