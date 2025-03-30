class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if n == 1:
            return [0]
        adj = defaultdict(list)
        for i, j in edges:
            adj[i].append(j)
            adj[j].append(i)
        
        ans = []
        def find_max(start_p, l=None):
            maxlayer = 0
            max_point = 0
            bfs = deque([(start_p,0)])
            visited = set()
            while bfs:
                p, layer = bfs.popleft()
                if p in visited:
                    continue
                visited.add(p)
                for p_adj in adj[p]:
                    bfs.append((p_adj, layer+1))
                
                if layer > maxlayer:
                    maxlayer = layer
                    max_point = p
                if l:
                    if l & 1:
                        if layer == l // 2 or layer == l//2 + 1:
                            ans.append(p)
                    else:
                        if layer == l // 2:
                            ans.append(p)
            return max_point, maxlayer
        
        e1, l = find_max(0)
        #print(e1, l)
        e2, l = find_max(e1)
        #print(e2, l)
        find_max(e1, l)
        ans1 = ans
        ans = []
        find_max(e2, l)
        return list(set(ans).intersection(set(ans1)))
        
            
            
        