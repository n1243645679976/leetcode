        def dijkstra(src, adj, n):
            """
            input:
                src: source
                adj: diction of "from" to "cost, to"
                n: number of nodes
            output:
                dp: list, length of which is n, contains the minimum distance to all points.
                
            """
            visited = set()
            dp = [inf] * n
            dp[src] = 0
            dis = [(0, src)]
            while dis:
                cost, src = heappop(dis)
                if src not in visited:
                    visited.add(src)
                    for t, w in adj[src]:
                        if t not in visited:
                            if dp[src] + w < dp[t]:
                                dp[t] = cost + w
                                heapq.heappush(dis, (dp[t], t))
            return dp