class Solution
{
public:
    int calculate(string s)
    {
        long long result = 0;
        int sign = 1;
        long long number = 0;
        stack<long long> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;

            if (isdigit(s[i]))
            {
                number = number * 10 + (s[i] - '0');
            }
            else if (s[i] == '+')
            {
                result += number * sign;
                sign = 1;
                number = 0;
            }
            else if (s[i] == '-')
            {
                result += number * sign;
                sign = -1;
                number = 0;
            }
            else if (s[i] == '(')
            {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
                number = 0;
            }
            else if (s[i] == ')')
            {

                result += number * sign;
                number = 0;

                int prevSign = st.top();
                st.pop();
                long long prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }

        return result + number * sign;
    }
};