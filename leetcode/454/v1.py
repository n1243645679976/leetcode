class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        n12 = Counter()
        n34 = Counter()
        for a, b in product(nums1, nums2):
            n12[a+b] += 1
        for c, d in product(nums3, nums4):
            n34[c+d] += 1
        
        ans = 0
        for key in n34.keys():
            ans += n34[key] * n12[-key]
        return ans