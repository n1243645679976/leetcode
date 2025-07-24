class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        bfs = deque([(src, 0, 0)]) # node, cost, stops
        cheapest = [1e9 for i in range(n)]
        cheapest[src] = 0
        ans = 1e9
        adj = defaultdict(list)
        for f, t, c in flights:
            adj[f].append([t, c])
        while bfs:
            node, cost, stop = bfs.popleft()
            #print(node, cost, stop)
            if cost > cheapest[node]:
                continue
            if stop > k+1:
                return ans if ans != 1e9 else -1
            if node == dst and ans > cost:
                ans = cost
                continue
            #print('#', node, cost, stop)
            cheapest[node] = cost
            for nextnode, nextcost in adj[node]:
                bfs.append((nextnode, cost + nextcost, stop+1))
        return ans if ans != 1e9 else -1