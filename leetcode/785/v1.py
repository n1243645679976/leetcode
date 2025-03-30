class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        color = [0 for _ in range(len(graph))]
        def dfs(node):
            for p in graph[node]:
                #print(p, node, color)
                if color[p] != 0:
                    if color[p] != -color[node]:
                        return False
                else:
                    color[p] = -color[node]
                    if not dfs(p):
                        return False
            return True
        for i in range(len(graph)):
            if color[i]:
                continue
            else:
                color[i] = 1
                if not dfs(i):
                    return False
        return True