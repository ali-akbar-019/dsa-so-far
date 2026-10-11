class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 1; i <= n; i++){
            int num = nums[i-1];
            if(n % i == 0){
                sum += (num * num);
            }
        }
        return sum;
    }
};