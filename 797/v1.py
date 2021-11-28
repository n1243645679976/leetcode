class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []
        def dfs(point, graph, lis):
            if point == len(graph) - 1:
                ans.append(lis.copy())
                return 
            for g in graph[point]:
                lis.append(g)
                dfs(g, graph, lis)
                lis.pop()
            return
        dfs(0, graph, [0])
        return ans
        