		
		def findOrderStart0(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
			graph = {i: [] for i in range(numCourses)}
			cnt = 0
			top_ord=[]
			for course in prerequisites:
				i,j = course
				graph[j].append(i)
				
			in_deg = [0]*numCourses
			for i in graph:
				for j in graph[i]:
					in_deg[j]+=1
					
			que = Deque()
			for i,val in enumerate(in_deg):
				if val == 0:
					que.append(i)
					
			while len(que)>0:
				cur = que.popleft()
				top_ord.append(cur)
				for val in graph[cur]:
					in_deg[val]-=1
					if in_deg[val]==0:
						que.append(val)
				cnt+=1

			if cnt != numCourses:
				return []
			else:
				return top_ord
        def findOrderStart1(numCourses: int, prerequisites: List[List[int]]) -> List[int]:
            graph = {i: [] for i in range(numCourses)}
            cnt = 0
            top_ord=[]
            for course in prerequisites:
                i,j = course
                graph[j].append(i)

            in_deg = [0]*numCourses
            for i in graph:
                for j in graph[i]:
                    in_deg[j]+=1

            que = Deque() # start from 0
            for i,val in enumerate(in_deg):
                if val == 0:
                    que.append(i)
            #print(que)
            que.popleft()  # <------------------------------------------ start from 0 -> popleft
            while len(que)>0:
                cur = que.popleft()
                top_ord.append(cur)
                for val in graph[cur]:
                    in_deg[val]-=1
                    if in_deg[val]==0:
                        que.append(val)
                cnt+=1
			
            if cnt != numCourses - 1: # or < -------------------------------- numCourses
                return []
            else:
                return top_ord