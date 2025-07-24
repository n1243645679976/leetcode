class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        i = -len(gas)
        j = -len(gas)
        su = 0
        while i < 0:
            while su >= 0:
                #print(i, j, '1')
                su += gas[i] - cost[i]
                i += 1
                if i == j + len(gas):
                    if su >= 0:
                        return j + len(gas)
                    else:
                        return -1
            while su < 0:
                #print(i, j, '2')
                su -= gas[j] - cost[j]
                j += 1
        return -1
            
            