class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int a1 = nums[0];
        int a2 = nums[1];
        int a3;
        int ans = 0, count = 0, ln = nums.size();
        for(int i=2;i<ln;++i){
            a3 = nums[i];
            if(a2 - a1 == a3 - a2){
                ++count;
            }
            else{
                ans += (count+1) * (count) / 2;
                count = 0;
            }
            a1 = a2;
            a2 = a3;
        }
        ans += (count+1) * (count) / 2;
        return ans;
    }
};