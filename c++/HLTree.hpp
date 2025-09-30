

namespace chh{
    long long op(long long a, long long b){return a+b;}
    long long e(){return 0;}
    using segtree = atcoder::segtree<long long, op, e>;
    class HLTree{
    public:
        int n, p;
        // top: top node of the same chain but not to top chain, jump chain will call parent[top[x]]
        vector<int> size, depth, heavy_child, dfn, top, parent;
        segtree sg; 
        // 1-indexed, root = 1
        HLTree(int _size) : n(_size), p(1), size(n), sg(n), depth(n), parent(n), heavy_child(n, -1), dfn(n), top(n) {}
        void build(vector<vector<array<int, 2>>>& adj){
            assert(adj[0].size() == 0);
            auto set_heavy_child = [&](auto& set_heavy_child, int x, int par, int d) -> void {
                parent[x] = par;
                depth[x] = d;
                for(auto [y, w]:adj[x]) if(y != par) {
                    set_heavy_child(set_heavy_child, y, x, d + 1);
                    size[x] += size[y];
                    if(heavy_child[x] == -1 || size[heavy_child[x]] < size[y]) heavy_child[x] = y;
                }
            };
            int ind = 0; auto set_dfn_for_segtree = [&](auto& set_dfn_for_segtree, int x, int par, int t, int w) -> void {
                dfn[x] = ind++, top[x] = t;
                sg.set(dfn[x], w);
                for(auto [y, w]:adj[x]) if(y != par) {
                    if(y == heavy_child[x]) set_dfn_for_segtree(set_dfn_for_segtree, heavy_child[x], x, t, w);
                    else set_dfn_for_segtree(set_dfn_for_segtree, y, x, y, w);
                }
            };
            set_heavy_child(set_heavy_child, p, p, 0);
            set_dfn_for_segtree(set_dfn_for_segtree, p, 0, p, 0);
        }
        // checked : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/1605394026
        int lca(int u, int v){
            cout<<top[u]<<" "<<top[v]<<" "<<depth[u]<<" "<<depth[v]<<endl;
            while(top[u] != top[v]){
                if(depth[top[u]] < depth[top[v]]) v = parent[top[v]];
                else u = parent[top[u]];
            }
            cout<<top[u]<<" "<<top[v]<<" "<<depth[u]<<" "<<depth[v]<<endl;
            if(depth[u] < depth[v]) return u;
            else return v;
        }
        // checked for v = 1 : https://leetcode.com/problems/shortest-path-in-a-weighted-tree/submissions/1605380971
        long long dist(int u, int v){
            long long res = 0;
            while(top[u] != top[v]){
                if(depth[u] < depth[v]) res = op(res, sg.prod(dfn[top[v]], dfn[v] + 1)), v = parent[top[v]];
                else res = op(res, sg.prod(dfn[top[u]], dfn[u] + 1)), u = parent[top[u]];
            }
            if(depth[u] < depth[v]) res = op(res, sg.prod(dfn[u] + 1, dfn[v] + 1));
            else if(depth[u] > depth[v]) res = op(res, sg.prod(dfn[v] + 1, dfn[u] + 1));
            return res;
        }
        // checked for v = 1 : https://leetcode.com/problems/shortest-path-in-a-weighted-tree/submissions/1605380971
        void update(int u, int v, int w){
            if(depth[u] < depth[v]) sg.set(dfn[v], w);
            else sg.set(dfn[u], w);
        }
    };
}