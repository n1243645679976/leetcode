class Tree{
public:
    int par[100001][20] = {0};
    int depth[100001] = {0};
    void add(int n, int pa, int d){ // node, parent, depth
        par[n][0] = pa;
        depth[n] = d;
        FOR(i, 1, 20) {
            if(par[n][i-1] == -1) par[n][i] = -1;
            else par[n][i] = par[par[n][i-1]][i-1];
        }
    }
    int lca(int p, int q){ 
        if(depth[q] < depth[p]) swap(q, p);
        int diff = depth[q] - depth[p], b = 0;
        while(diff){
            if(diff & 1) q = par[q][b];
            diff>>=1;
            b++;
        }
        if(p == q) return p;
        F0Rr(i, 20) if(par[p][i] != par[q][i]) p = par[p][i], q = par[q][i];
        return par[p][0];
    }
};