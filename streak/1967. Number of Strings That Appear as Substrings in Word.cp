class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(auto & patt: patterns){
            if(word.find(patt) != string::npos){
                ans+=1;
            }
        }
        return ans;
    }
};