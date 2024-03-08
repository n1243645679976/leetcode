
#define TreeNode TN
#define segtree_constMX
namespace segtree{
// ref: https://atcoder.jp/contests/abc332/submissions/48377125
    static int MX;
	class TreeNode{
	public:
		mint99 val;
		mint99 prob;
		TreeNode(){
            val = 0, prob = 1;
		}
		TreeNode(int a, int u){
            val = a, prob = u;
		}
		TreeNode(mint99 a, mint99 u){
            val = a, prob = u;
		}
        void set(int L, int R, ints2 au){
            auto [a, u] = au;
            val = a, prob = u;
        }
		bool operator==(TreeNode& b){
			return this->val.x == b.val.x && this->prob.x == b.prob.x;
		}
	};
	class LazyNode{
	public:
		mint99 val;
		mint99 prob;
		LazyNode(){
			val = 0, prob = 1;
		}
		LazyNode(int a, int u){
            val = a, prob = u;
		}
		LazyNode(mint99 a, mint99 u){
            val = a, prob = u;
		}
		bool operator==(LazyNode& b){
			return this->val.x == b.val.x && this->prob.x == b.prob.x;
		}
	};
#ifdef segtree_constMX
	TreeNode tree[400002];
	LazyNode lazy[400002];
#else
    vector<TreeNode> tree;
    vector<LazyNode> lazy;
#endif
    class segtree{
	public:
		LazyNode nullLazy;
        TreeNode nullTree;
		TreeNode combineTreeNode(TreeNode a, TreeNode b){
            return TreeNode(b.val + (b.prob) * a.val, a.prob * b.prob);
		}
		TreeNode applyLazy(LazyNode& a, TreeNode& b){
            return TreeNode(b.val + (b.prob) * a.val, a.prob * b.prob);
		}
		LazyNode combineLazyNode(LazyNode& a, LazyNode& b){
            return LazyNode(b.val + (b.prob) * a.val, a.prob * b.prob);
		}
        segtree(int n){
#ifdef segtree_constMX
			MX = n;
#else
            MX = n, tree.resize(MX*2), lazy.resize(MX*2);
#endif
            build(0);
        }
        template<typename T>
        segtree(int n, vector<T>& m){
#ifdef segtree_constMX
			MX = n;
#else
            MX = n, tree.resize(MX*2), lazy.resize(MX*2);
#endif
            build(0, m);
        }
        void build(int ind, int L=0, int R=MX-1){
            if(L == R) return ;
            int M = (L+R) >> 1;
            int leftind = ind+1, rightind = ind + ((M - L + 1) << 1);
            build(leftind, L, M);
            build(rightind, M + 1, R);
            pull(ind, L, R);
        }
        template<typename T>
        void build(int ind, vector<T>& v, int L=0, int R=MX-1){
            if(L == R) {tree[ind].set(L, R, v[L]); return ;}
            int M = (L+R) >> 1;
            int leftind = ind+1, rightind = ind + ((M - L + 1) << 1);
            build(leftind, v, L, M);
            build(rightind, v, M + 1, R);
            pull(ind, L, R);
        }
		void push(int ind, int L, int R){
            int M = (L+R) >> 1;
            int leftind = ind+1, rightind = ind + ((M - L + 1) << 1);
			tree[ind] = applyLazy(lazy[ind], tree[ind]);
			if(L != R) lazy[leftind] = combineLazyNode(lazy[ind], lazy[leftind]), lazy[rightind] = combineLazyNode(lazy[ind], lazy[rightind]);
			lazy[ind] = LazyNode();
		}
		void pull(int ind, int L, int R){ // pull after both children are pushed
            int M = (L+R) >> 1;
            int leftind = ind+1, rightind = ind + ((M - L + 1) << 1);
			tree[ind] = combineTreeNode(tree[leftind], tree[rightind]);
		}
		void update(int lo, int hi, LazyNode& node, int ind=0, int L=0, int R=MX-1){
			push(ind, L, R);
			if(lo > R || hi < L) return ;
			if(lo <= L && R <= hi) {
				lazy[ind] = combineLazyNode(node, lazy[ind]);	
				push(ind, L, R);
				return ;
			}
            int M = (L+R) >> 1;
            int leftind = ind+1, rightind = ind + ((M - L + 1) << 1);
			update(lo, hi, node, leftind, L, M); update(lo, hi, node, rightind, M+1, R);
			pull(ind, L, R);
		}
		TreeNode query(int lo, int hi, int ind=0, int L=0, int R=MX-1){
			push(ind, L, R);
			if(lo > R || hi < L) return TreeNode();
			if(lo <= L && R <= hi){
				return tree[ind];
			}
            int M = (L+R) >> 1;
            int leftind = ind+1, rightind = ind + ((M - L + 1) << 1);
			// pull(ind, L, R); no pull here because tree[ind*2] and tree[ind*2+1] not updated like update(****) here (pull is used after update).
			return combineTreeNode(query(lo, hi, leftind, L, M), query(lo, hi, rightind, M+1, R));
		}
	};
}