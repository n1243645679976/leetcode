class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int max_usable_bit = 1;
        int ans = 0;
        while(startValue < target){
            startValue <<= 1;
            max_usable_bit <<= 1;
            ans++;
        }
        int diff = startValue - target;
        while(max_usable_bit != 0){
            if(max_usable_bit & 1){
                ans += diff;
            }
            else{
                ans += diff & 1;
            }
            diff >>= 1;
            max_usable_bit >>= 1;
        }
        return ans;
    }
};