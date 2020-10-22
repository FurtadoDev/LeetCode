class Solution {
public:
    int climbStairs(int n) {
        return getNumWaysToClimbTo(n);
    }
    
    int getNumWaysToClimbTo(int n){
        int answer = 0;
        vector<int> numWays;
        
        
        if(n == 1){
            return 1;
        }
        else if(n == 2){
            return 2;
        }else{
            numWays.reserve(n+1);
            numWays[0] = 0;
            numWays[1] = 1;
            numWays[2] = 2;
            for(int i = 3; i <= n; i++){
                numWays[i] = numWays[i-1] + numWays[i-2];
            }
        
            answer = numWays[n];
            numWays.clear();
            return answer;
        }
        
   
            
        /** APPROACH 2: Time Limit Exceeded
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        else
            return getNumWaysToClimbTo(n-1) +  getNumWaysToClimbTo(n-2); //since there are two ways to get to any node, either you can take one step or two steps
        **/
    }
};