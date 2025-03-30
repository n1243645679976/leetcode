class Solution(object):
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        tar = 0
        heap = deque()
        visited_state = set()
        for i in range(len(graph)):
            heap.append((0, i, 1 << i))
            tar <<= 1
            tar += 1
        while heap:
            step, now, visited = heap.popleft()
            if visited == tar:
                return step
            for q in graph[now]:
                state = (1 << (13+q)) + (visited | (1<<q))
                if state in visited_state:
                    continue
                visited_state.add(state)
                heap.append((step+1, q, visited | (1<<q)))
                
            