class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        ini = [[] for i in range(len(nums)+1)]
        c = Counter(nums)
        for i, n in c.items():
            ini[n].append(i)
        return list(chain(*ini))[::-1][:k]