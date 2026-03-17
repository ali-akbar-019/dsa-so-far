class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>prev(n, 0);
        vector<int>curr(n,0);
        int maxArea = 0;
        for(int i = 0 ; i < m ;i++){
            curr = matrix[i];
            for(int j = 0 ; j < n ; j++){
                if(curr[j] == 1){
                    curr[j] +=prev[j];
                }
            }
            vector<int>heights = curr;
            sort(begin(heights), end(heights), greater<int>());
            
            for(int h= 0; h < n; h++){
                int base = (h + 1);
                int height = heights[h];
                int area = base * height;
                maxArea = max(area, maxArea); 
            }
            prev = curr;
        }
        return maxArea;
    }
};