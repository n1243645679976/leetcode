class Solution {
public:
    int countOrders(int n) {
        // 2n! / (2^n)
        long long ans=1, mod = 1e9 + 7;
        for(int i=1;i<=n;++i){
            ans *= i;
            ans %= mod;
        }
        for(int i=1;i<=2*n;i+=2){
            ans *= i;
            ans %= mod;
        }
        return ans;
    }
};