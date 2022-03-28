class Solution {
public:
    bool bs(vector<int>& nums, int target, int l, int r){
        int mid;
        while(l < r){
            mid = (l+r)/2;
            if(nums[mid] == target) return true;
            if(nums[mid] == nums[0]) return bs(nums, target, l, mid-1) || bs(nums, target, mid+1, r);
            if(target > nums[0]){
                if(nums[mid] < nums[0]){
                    r = mid - 1;
                }
                else if(nums[mid] > target){
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if(target < nums[0]){
                if(nums[mid] > nums[0]){
                    l = mid + 1;
                }
                else if(nums[mid] < target){
                    l = mid + 1;
                }
                else r = mid - 1;
            }
        }
        
        if(nums[l] == target) return true;
        return false;
    }
    bool search(vector<int>& nums, int target) {
        if(nums[0] == target) return true;
        return bs(nums, target, 0, nums.size()-1);
    }
};