class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int countLeft = 0;
        int countUp = 0;
        for (int i = 0; i < moves.length(); i++)
        {
            if (moves[i] == 'L')
            {
                countLeft++;
            }
            else if (moves[i] == 'R')
            {
                countLeft--;
            }
            else if (moves[i] == 'U')
            {
                countUp++;
            }
            else if (moves[i] == 'D')
            {
                countUp--;
            }
        }
        // so if the magnitude of all were the same then it would have returned from where it started
        return countUp == 0 && countLeft == 0;
    }
};