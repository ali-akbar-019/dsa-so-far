class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       bool isOddPresent = false;
       bool allEven = true;
       int n = nums1.size();
       for(int i = n -1 ;i >= 0 ; i--){
            if(nums1[i] % 2 != 0 && isOddPresent == false){
                allEven = false; 
                break;
            }
            if(nums1[i] % 2 == 0 && isOddPresent==false ){
                isOddPresent = true;
            }
       }
       if(allEven){
        return true;
       }
        bool isEvenPresent = false;
       bool allOdd = true;
       
       for(int i = n -1 ;i >= 0 ; i--){
            if(nums1[i] % 2 == 0 && isEvenPresent == false){
                allOdd = false; 
                break;
            }
            if(nums1[i] % 2 != 0 && isEvenPresent==false ){
                isEvenPresent = true;
            }
       }
       if(allOdd){
        return true;
       }
       return false;
    }
};