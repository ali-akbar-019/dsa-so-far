class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        // its very simple yar
        // aik pori array aik valid subarray ha
        // then tm us ka max and min nikal lo
        // and tm us ka diff k times nikal k add kar sakte
        // formula = k * (max(array) - min(array))
        // to hamesha jo best ho ga max - min wo k times ham likh de ge
        // that will be the answer
        long long global_max = INT_MIN;
        long long global_min = INT_MAX;
        for (auto &num : nums)
        {
            if (num > global_max)
            {
                global_max = num;
            }
            if (num < global_min)
            {
                global_min = num;
            }
        }
        //
        long long answer = k * (global_max - global_min);
        return answer;
    }
};