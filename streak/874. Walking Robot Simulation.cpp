class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //first of all make the unoredered_set so taht we can access the obstacles in O(1) time
        unordered_set<string> st;
        //enhanced for loop
        for(vector<int> &obs : obstacles){
            string  key = to_string(obs[0]) + "_"+to_string(obs[1]);
            //
            st.insert(key); //now we can access it in o(1) time
        }
        //
        int x = 0;
        int y = 0; //from the origin
        int maxD = 0;
        //
        //first its pointing to the nort
        pair<int, int> dir = {0, 1}; 
        for(int i = 0 ; i < commands.size() ;i++){
            //
            if(commands[i] == -2){
                //then it is 90 deg left
                dir = {-dir.second, dir.first};
            }
            else if(commands[i] == -1){
                //then it is a 90 deg right
                dir = {dir.second, -dir.first};

            }else{
                for(int step=0; step< commands[i]; step++){
                    //we just have to move step by step and check
                    int newX =x+ dir.first;
                    int newY =y+ dir.second;
                    //
                    string nextVal = to_string(newX)+"_"+to_string(newY);
                    //check in the set
                    if(st.find(nextVal) != st.end()){
                        //means we have an obstacle so block and break
                        break;
                    }
                    x = newX;
                    y = newY;
                
                }
            }
            //so update the maxD
            maxD= max(maxD, x*x + y*y);
        }
        return maxD;

        
    }
};