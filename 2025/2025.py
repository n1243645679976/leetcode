class Solution(object):
    def waysToPartition(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        q = []
        _sum = 0
        for num in nums:
            _sum += num
            q.append(_sum)
        
        _sum = 0
        r = []
        left = defaultdict(int)
        right = defaultdict(int)
        for i in range(len(nums)-1, -1, -1):
            _sum += nums[i]
            r.append(_sum)
        
        r = list(reversed(r))
        for i in range(len(nums)-1):
            right[q[i] - r[i+1]] += 1
        ans = left[0] + right[0]
        for i in range(len(nums)):
            diff = k - nums[i]
            _sum = right[-diff] 
            _sum += left[diff]
            
            if i != len(nums) - 1:
                right[q[i] - r[i+1]] -= 1
                left[q[i] - r[i+1]] += 1
            ans = max(ans, _sum)
        return ans
        
            
        
        