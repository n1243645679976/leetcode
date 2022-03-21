class Solution {
public:
    int dp[2][1050];
    int *dp1, *dp2;
    
    void re(int *d){
        for(int i=0;i<1050;i++) d[i] = 0;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp[0][0] = 1;
        dp1 = dp[0];
        dp2 = dp[1];
        for(int r=0;r<n;r++){
            for(int i=0;i<target;i++){
                for(int j=1;j<=k;j++){
                    dp2[i+j] += dp1[i];
                    dp2[i+j] %= 1000000007;
                }
            }
            swap(dp1, dp2);
            re(dp2);
        }
        return dp1[target];
        
    }
};