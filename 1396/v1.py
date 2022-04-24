class UndergroundSystem(object):

    def __init__(self):
        self.t = {}
        self.time = defaultdict(lambda :defaultdict(lambda :[0, 0]))
        

    def checkIn(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        self.t[id] = (stationName, t)

    def checkOut(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        ss, st = self.t[id]
        self.time[ss][stationName][0] += t - st
        self.time[ss][stationName][1] += 1
        #print(self.time)

    def getAverageTime(self, startStation, endStation):
        """
        :type startStation: str
        :type endStation: str
        :rtype: float
        """
        return float(self.time[startStation][endStation][0]) / self.time[startStation][endStation][1]


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)