class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        bus_stop = defaultdict(list)
        for i, r in enumerate(routes):
            for q in r:
                bus_stop[q].append(i)
        
        queue = deque([[source, 1]])
        visited_stop = set()
        visited_point = set()
        while queue:
            p, i = queue.popleft()
            for stop in bus_stop[p]:
                if stop in visited_stop:
                    continue
                visited_stop.add(stop)
                for q in routes[stop]:
                    if q == target:
                        return i
                    if q in visited_point:
                        continue
                    visited_point.add(q)
                    queue.append([q, i+1])
        return -1