class Solution {
public:
    bool check(int mid, vector<int>& nums, int m){
        int c = 0;
        for(int num: nums){
            if(c+num <= mid){
                c += num;
            }
            else{
                c = num;
                m--;
                if(m <0) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0), mid;
        while(l < r){
            mid = (l+r) / 2;
            if(check(mid, nums, m-1)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};