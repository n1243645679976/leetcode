class Solution:
    def isPrintable(self, gr: List[List[int]]) -> bool:
        # find boundary
        boundary = [(math.inf, math.inf, -math.inf, -math.inf) for i in range(61)]
        for i, j in product(range(len(gr)), range(len(gr[0]))):
            l, d, r, u = boundary[gr[i][j]]
            l, d, r, u = min(l, i), min(d, j), max(r, i), max(u, j)
            boundary[gr[i][j]] = (l, d, r, u)
        
        # make topo graph
        topo = defaultdict(set)
        for color in range(len(boundary)):
            l, d, r, u = boundary[color]
            if l != math.inf:
                for i, j in product(range(l, r+1), range(d, u+1)):
                    if gr[i][j] != color:
                        topo[color].add(gr[i][j])
        
        # find cycle
        in_progress = set()
        visited = set()
        def dfs(node):
            in_progress.add(node)
            for adj in topo[node]:
                if (adj in in_progress) or (adj not in visited and not dfs(adj)):
                    return False
            in_progress.remove(node)
            visited.add(node)
            return True
        
        for color in range(61):
            if not dfs(color):
                return False
        return True
                
            
        