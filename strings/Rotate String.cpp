class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.size();
        if (n != goal.size())
        {
            return false;
        }
        string doubleS = s + s; // the rotation will definitely be in this
        return doubleS.find(goal) != string::npos;
    }
};