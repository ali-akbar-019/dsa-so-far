class Solution
{
public:
    string countOfAtoms(string formula)
    {
        int n = formula.size();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i = 0;
        while (i < n)
        {
            if (formula[i] == '(')
            {
                // means a new formula so insert a new map in the stack
                st.push(unordered_map<string, int>());
                i++;
            }
            else if (formula[i] == ')')
            {
                // we found a formula and now we have to insert it in the stack
                unordered_map<string, int> curr = st.top();
                st.pop();
                // now we have to modify this
                i++;
                string currNumber;
                while (i < n && isdigit(formula[i]))
                {
                    currNumber += formula[i];
                    i++;
                }
                //
                int number = currNumber.empty() ? 1 : stoi(currNumber);
                for (auto &it : curr)
                {
                    string element = it.first;
                    int countOfIt = it.second;
                    // update it
                    st.top()[element] += countOfIt * number;
                }
            }
            else
            {
                // we have a alphabet
                string element;
                element += formula[i];
                i++;
                // now the small
                while (i < n && isalpha(formula[i]) && islower(formula[i]))
                {
                    element += formula[i];
                    i++;
                }
                // now the number
                string countOfElement;
                while (i < n && isdigit(formula[i]))
                {
                    countOfElement += formula[i];
                    i++;
                }
                int number = countOfElement.empty() ? 1 : stoi(countOfElement);
                st.top()[element] += number;
            }
        }
        // sorted
        string result;
        map<string, int> sortedMap(begin(st.top()), end(st.top()));
        for (auto &it : sortedMap)
        {
            string el = it.first;
            int count = it.second;
            result += el;
            if (count > 1)
            {
                result += to_string(count);
            }
        }
        return result;
    }
};