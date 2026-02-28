class Solution
{
public:
    int M = 1e9 + 7;
    int numberOfWays(string corridor)
    {
        vector<int> indices_of_seats;
        int n = corridor.size();
        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
            {
                indices_of_seats.push_back(i);
            }
        }
        // check if there are seats or not
        if (indices_of_seats.empty() || indices_of_seats.size() % 2 != 0)
        {
            return 0;
        }
        long long result = 1;
        int prev_first_index = indices_of_seats[1];
        for (int i = 2; i < indices_of_seats.size(); i += 2)
        {
            int curr = indices_of_seats[i];
            int length = curr - prev_first_index;
            result = result * length % M;
            prev_first_index = indices_of_seats[i + 1];
        }
        return result;
    };
};