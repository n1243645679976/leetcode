class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        ans = []
        adj = defaultdict(list)
        in_b = defaultdict(int)
        for i in range(numCourses):
            in_b[i] = 0
        for a, b in prerequisites:
            adj[b].append(a)
            in_b[a] += 1
        
        first = []
        for b in in_b.keys():
            if in_b[b] == 0:
                first.append(b)
                
        ansset = set()
        in_prog = set()
        def dfs(r):
            #print(r, in_prog, ans, ansset)
            if r in in_prog:
                return False
            in_prog.add(r)
            for n in adj[r]:
                if not dfs(n):
                    return False
            in_prog.remove(r)
            if r not in ansset:
                ansset.add(r)
                ans.append(r)
            return True
        
        for f in first:
            if not dfs(f):
                return []
            in_prog = set()

        if len(ans) != numCourses:
            return []
        else:
            return list(reversed(ans))
        
                
            
            