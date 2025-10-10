namespace chh{
  class graph{
  public:
    int n_edges, n;
    vector<vector<array<long long, 3>>> adj; // next, weight, edge_id
    vector<array<long long, 3>> eds;   // from, to, weight
    graph(int n) : adj(n){this->n = n;}
    graph(int n, int m) : adj(n) {
      this->n = n, n_edges = m;
    }
    void add_edge(int u, int v, int w = 1, int offset = 1, int bidirectional = 1){
      u -= offset;
      v -= offset;
      adj[u].push_back({v, w, int(eds.size())}); 
      if(bidirectional) adj[v].push_back({u, w, int(eds.size())});
      eds.push_back({u, v, w});
      n_edges++;
    }
    void read_edge(int offset = 1, bool read_weight=true){
      for(int i=0;i<n_edges;i++){
        long long a, b, w = 1; cin>>a>>b;
        if(read_weight) cin>>w;
        add_edge(a, b, w, offset);
      }
    }
    // https://leetcode.com/problems/network-delay-time/submissions/1431214165
    vector<long long> shortest_path(int source){
      priority_queue<array<long long, 2>, vector<array<long long, 2>>, greater<array<long long, 2>>> now;
      now.push({0, source});
      vector<long long> dist(n, -1); dist[source] = 0;
      while(now.size()){
        auto [d, x] = now.top(); now.pop();
        if(d > dist[x]) continue;
        for(auto [y, dd, edid]:adj[x]){
          if(dist[y] == -1 || dist[y] > d + dd) dist[y] = d + dd, now.push({d + dd, y});
        }
      }
      return dist;
    }
    // https://leetcode.com/problems/critical-connections-in-a-network/submissions/1431213372
    vector<int> get_bridges(){
      vector<int> been(n), go_up(n), go_down(n), dfsn(n);
      vector<int> bridges(n_edges);
      int dfs_ind = 0;
      auto dfs = [&](auto& dfs, int x, int par) -> int {
        been[x] = true;
        dfsn[x] = dfs_ind++;
        int ttgo_up = 0;
        for(auto [y, w, edid]:adj[x]){
          if(y == par) continue;
          if(been[x] && been[y]){
            if(dfsn[x] > dfsn[y]) go_up[x]++, go_down[y]++;
            continue;
          }
          int y_go_up = dfs(dfs, y, x);
          ttgo_up += y_go_up;
          if(!y_go_up) bridges[edid] = true;
        }
        ttgo_up += go_up[x] - go_down[x];
        return ttgo_up;
      };
      for(int i=0;i<n;i++) if(!been[i]) {
        dfs(dfs, i, i);
      }
      return bridges;
    }
  };
}