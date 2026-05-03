class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        string d_s = s + s;
        for (int i = 0; i < d_s.size(); i++)
        {
            string to_check = d_s.substr(i, goal.size());
            if (to_check == goal)
            {
                return true;
            }
        }
        return false;
    }
};