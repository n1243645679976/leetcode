
namespace chh{
  // S should be a Commutative Monoid 
  template<typename S, S (*op)(S, S), S e()>
  class _TreapNode{
  public:
    inline static mt19937_64 gen = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
    inline static uniform_int_distribution<ll> rnd = uniform_int_distribution<ll>(0,LLONG_MAX); //usage: long long xx = rnd(gen);
    S data, adata;
    long long priority;
    int subtreesize;
    array<_TreapNode*, 2> kids;
    _TreapNode(S d) : data(d), adata(d), priority(rnd(gen)), subtreesize(1), kids({nullptr, nullptr}) {}
    _TreapNode(_TreapNode&& other) noexcept : data(other.data), adata(other.adata), priority(other.priority), kids(other.kids) {}
    ~_TreapNode(){
      dbg(kids[0], kids[1])
      delete kids[0];
      delete kids[1];
    }
    void recalc(){
      adata = data;
      subtreesize = 1;
      if(kids[0] != nullptr) adata = op(kids[0]->adata, adata), subtreesize += kids[0]->subtreesize;
      if(kids[1] != nullptr) adata = op(adata, kids[1]->adata), subtreesize += kids[1]->subtreesize;
    }
    void set(S x) {
      data = x;
      recalc();
    }
  };
  template<typename S, S (*op)(S, S), S e()>
  class Treap{
    // 禁止 copy, auto t = split(a, 42); auto [l, r] = t; X
    // 只能 move, auto t = split(a, 42); auto [l, r] = move(t); O
  public:
    using TreapNode = _TreapNode<S, op, e>;
    Treap() : root(nullptr) {}
    
    Treap(const Treap&) = delete;
    Treap& operator=(const Treap&) = delete ; // 禁止 copy assign
    Treap(Treap&& other) noexcept : root(other.root) {other.root = nullptr;}
    Treap(int sz) : root(nullptr) {
      for(int i=0;i<sz;i++) root = merge_nodes(root, new TreapNode(e()));
    }
    Treap(vector<S>& arr) : root(nullptr) {
      for(int i=0;i<arr.size();i++) root = merge_nodes(root, new TreapNode(arr[i]));
    }
    Treap& operator=(Treap&& other) noexcept {
      if (this != &other) {
          delete root;
          root = other.root;
          other.root = nullptr;
      }
      return *this;
    }
    ~Treap(){
      delete root;
      root = nullptr;
    }
    array<Treap, 2> split(int leftsize){
      // cut [0, leftsize)
      // you cannot use this again (setting root = 0)
      assert(0 <= leftsize && leftsize <= root->subtreesize);
      if(leftsize) assert(root && leftsize <= root->subtreesize);
      auto [l, r] = split_nodes(this->root, leftsize);
      root = nullptr;
      return {Treap(l), Treap(r)};
    }
    array<Treap, 3> split(int l, int r){
      // [0, l), [l, r), [r, n)
      assert(0 <= l && l <= r);
      if(r) assert(root && r <= root->subtreesize);
      auto [_l, _] = split(root, l);
      auto [_mid, _r] = split(_, r - l);
      root = nullptr;
      return {_l, _mid, _r};
    }
    void lmerge(Treap& left){root = merge_nodes(left.root, root); left.root = nullptr;}
    void lmerge(Treap&& left){root = merge_nodes(left.root, root); left.root = nullptr;}
    void rmerge(Treap& right){root = merge_nodes(root, right.root); right.root = nullptr;}
    void rmerge(Treap&& right){root = merge_nodes(root, right.root); right.root = nullptr;}
    void merge(Treap& right){root = merge_nodes(root, right.root); right.root = nullptr;}
    void merge(Treap&& right){root = merge_nodes(root, right.root); right.root = nullptr;}
    
    int size(){
      return this->root ? this->root->subtreesize : 0;
    }
    void set(int ind, S x){
      assert(0 <= ind && this->root && ind < this->root->subtreesize);
      set(this->root, ind, x);
    }
    S get(int ind){
      assert(this->root && ind < this->root->subtreesize);
      return get(this->root, ind);
    }
    S all_prod(){return root->adata;}
    void push_back(S&& x){
      root = merge_nodes(root, new TreapNode(x));
    }
    // S prod(int l, int r) {
    //   assert(0 <= l && l <= r && r <= this->root->subtreesize);
    //   return prod(this->root, l, r);
    // }
    void printdfs(TreapNode* node){
      if(!node) {cout<<"_"; return ;}
      cout<<node->adata.ma<<":(";
      printdfs(node->kids[0]);
      cout<<",";
      printdfs(node->kids[1]);
      cout<<")";
    }
    void printnode(TreapNode* node){ // DLR
      printdfs(node);
      cout<<endl;
    }
    void clear(){
      delete root;
      root = nullptr;
    }
    template <typename A, typename B>
    static Treap merge(A&& a, B&& b) {
      a.merge(b);
      auto c = move(a);
      a.root = nullptr; b.root = nullptr;
      return c;
    }
    // checked https://atcoder.jp/contests/practice2/submissions/70835898
    S prod(int l, int r){
      assert(0 <= l && l <= r);
      if(r) assert(root && r <= root->subtreesize);
      auto [_l, _] = split_nodes(root, l);
      auto [_mid, _r] = split_nodes(_, r-l);
      S res = _mid ? _mid->adata : e();
      root = merge_nodes(_l, _mid);
      root = merge_nodes(root, _r);
      return res;
    }
    TreapNode* root;
  private:
    Treap(TreapNode* other) noexcept : root(other) {}
    static void set(TreapNode* node, int ind, S x){
      int lsize = node->kids[0] ? node->kids[0]->subtreesize : 0;
      if(ind == lsize) node->set(x);
      else if(ind < lsize) set(node->kids[0], ind, x);
      else set(node->kids[1], ind - lsize - 1, x);
      node->recalc();
    }
    static S get(TreapNode* node, int ind){
      int lsize = node->kids[0] ? node->kids[0]->subtreesize : 0;
      if(ind == lsize) return node->data;
      else if(ind < lsize) return get(node->kids[0], ind);
      else return get(node->kids[1], ind - lsize - 1);
    }
    // checked : https://codeforces.com/gym/102787/submission/315296857
    static array<TreapNode*, 2> split_nodes(TreapNode* node, int leftsize){
      if(!node) return {nullptr, nullptr};
      if(leftsize == 0) return {nullptr, node};
      if(node->kids[0] && leftsize <= node->kids[0]->subtreesize){
        auto [left, right] = split_nodes(node->kids[0], leftsize);
        node->kids[0] = right;
        node->recalc();
        return {left, node};
      }
      else{
        int sz = leftsize - (node->kids[0] ? node->kids[0]->subtreesize : 0) - 1;
        auto [left, right] = split_nodes(node->kids[1], sz);
        node->kids[1] = left;
        node->recalc(); 
        return {node, right};
      }
    }

    // checked : https://codeforces.com/gym/102787/submission/315296857
    static TreapNode* merge_nodes(TreapNode* left, TreapNode* right){
      if(left == nullptr) return right;
      if(right == nullptr) return left;
      // keep the relative position, if add right, then try add left to right's left subtree (leave full right's right subtree).
      if(left->priority > right->priority){
        right->kids[0] = merge_nodes(left, right->kids[0]);
        right->recalc();
        return right;
      }
      else{
        left->kids[1] = merge_nodes(left->kids[1], right);
        left->recalc();
        return left;
      }
    }
  };
}

using Treap = chh::Treap<S, op, e>;
#define tmerge Treap::merge