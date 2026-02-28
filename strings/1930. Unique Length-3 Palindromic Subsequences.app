class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int result = 0;
        unordered_set<char> st;
        int n = s.size();
        for(int i = 0; i < n ;i++){
            st.insert(s[i]);
        }      
        //now we have the unique characters
        //take one by one
        int first_index = -1;
        int last_index = -1;
        for(auto &current_ch: st){
            for(int i = 0 ; i <n ; i++ ){
                if(s[i] == current_ch){
                    if(first_index == -1){
                        first_index = i;
                    }
                    last_index = i;
                }
            }
            //now we have the first and last index of it
            unordered_set<char> palindromeCharacters;
            for(int middle = first_index +1 ; middle < last_index ; middle++){
                palindromeCharacters.insert(s[middle]);
            }
            result+=palindromeCharacters.size();
            first_index = -1;
            last_index=-1;
        }
        return result;
    }
};