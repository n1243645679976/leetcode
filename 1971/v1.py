class Solution(object):
    def validPath(self, n, edges, start, end):
        """
        :type n: int
        :type edges: List[List[int]]
        :type start: int
        :type end: int
        :rtype: bool
        """
        visited = set()
        adj = defaultdict(list)
        for a,b in edges:
            adj[a].append(b)
            adj[b].append(a)
            
        def dfs(k):
            if k == end:
                return True
            for j in adj[k]:
                if j in visited:
                    continue
                visited.add(j)
                if dfs(j):
                    return True
            return False
        return dfs(start)