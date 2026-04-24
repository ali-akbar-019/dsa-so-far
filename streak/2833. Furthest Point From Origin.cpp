class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        // simple sa codee
        int left = 0;
        int right = 0;
        int dash = 0;
        for (auto &move : moves)
        {
            if (move == 'L')
                left++;
            if (move == 'R')
                right++;
            if (move == '_')
                dash++;
        }
        return abs(left - right) + dash;
    }
};