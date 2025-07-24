
class graph{
public:
  vector<vector<int>> adj;
  vector<array<int, 2>> edges;
  graph(int n):adj(n){}
  void add_edge(int u, int v){adj[u].push_back(v); edges.push_back({u, v});}
};
class treegraph : public graph{
public:
  vector<int> par, depth;
  vector<int> dfsin, dfsout;
  vector<int> dfsin2node;
  int ind;
  treegraph(int n) : graph(n), par(n), depth(n), dfsin(n), dfsout(n), dfsin2node(n) {}
  void build(int node=0, int d=0, int p=-1){
    if(p == -1) ind = 0;
    par[node] = p, depth[node] = d, dfsin2node[ind] = node, dfsin[node] = ind++;
    for(auto v:adj[node]) if(v != p) build(v, d+1, node);
    dfsout[node] = ind;
  }
  bool ischild(int u, int v){
    // return if v is u's child
    return dfsin[u] <= dfsin[v] && dfsin[v] < dfsout[u];
  }
};