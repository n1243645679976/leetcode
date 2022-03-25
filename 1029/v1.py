class Solution(object):
    def twoCitySchedCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        return sum(sorted([k[1] - k[0] for k in costs])[:len(costs)//2]) + sum([k[0] for k in costs])