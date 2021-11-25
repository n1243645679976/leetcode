int maxSubArray(int* nums, int numsSize){
    int i, sum=0, ans=-100000;
    for(i=0;i<numsSize;++i){
        sum+=nums[i];
        sum = sum<nums[i] ? nums[i]:sum;
        ans = sum>ans ? sum:ans;
    }
    return ans;
}