
        def eu(p):
            while adj[p]:
                n = adj[p].pop()
                eu(n)
            self.ans.append(p)