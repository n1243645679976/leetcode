
namespace LCA{
	const int MX = 200001;
    const int N = 20;
	int par[MX][N] = {0};
	int depth[MX] = {0};
	class LCA{
	public:
		void add(int n, int pa, int d){ // node, parent, depth
			par[n][0] = pa;
			depth[n] = d;
			rep(i, 1, N) {
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
			per(i, 19, -1) if(par[p][i] != par[q][i]) p = par[p][i], q = par[q][i];
			return par[p][0];
		}
		ints2 lcaM(int p, int q){ 
			// return: lca, lca_down from lower one if in subtree or from p
			if(p == q) return {p, -1};
			if(depth[q] < depth[p]) swap(q, p);
			int diff = depth[q] - depth[p] - 1, b = 0;
			if(depth[q] != depth[p]) while(diff){
				if(diff & 1) q = par[q][b];
				diff>>=1;
				b++;
			}
			if(par[q][0] == p) return {par[q][0], q};
			q = par[q][0];
			per(i, 19, -1) if(par[p][i] != par[q][i]) p = par[p][i], q = par[q][i];
			return {par[p][0], p};
		}
	};
}