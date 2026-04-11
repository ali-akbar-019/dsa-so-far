class Solution
{
public:
    vector<int> solve(string exp)
    {
        vector<int> result;
        for (int i = 0; i < exp.length(); i++)
        {
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*')
            {
                // now call the recursion for the left and the right part
                vector<int> left_part = solve(exp.substr(0, i));
                vector<int> right_part = solve(exp.substr(i + 1)); // i +1 se aage sara
                // ab bech me reh gaya operator
                for (auto &x : left_part)
                {
                    for (auto &y : right_part)
                    {
                        if (exp[i] == '+')
                        {
                            result.push_back(x + y);
                        }
                        else if (exp[i] == '-')
                        {
                            result.push_back(x - y);
                        }
                        else if (exp[i] == '*')
                        {
                            result.push_back(x * y);
                        }
                    }
                }
            }
        }
        if (result.empty())
        {
            return {stoi(exp)};
        }
        return result;
    }
    vector<int> diffWaysToCompute(string expression)
    {
        return solve(expression);
    }
};