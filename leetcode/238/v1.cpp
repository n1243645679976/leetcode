class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, ln = nums.size();
        vector<int> lr(ln);
        for(int i=0;i<ln;++i){
            lr[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for(int i=ln-1;i>=0;--i){
            lr[i] *= prod;
            prod *= nums[i];
        }
        return lr;
    }
};