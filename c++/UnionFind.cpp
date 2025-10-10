struct UnionFind {
    vector<int> par;
    vector<int> size;
    UnionFind(int N) : par(N), size(N) {
        for(int i = 0; i < N; i++) par[i] = i, size[i] = 1;
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        if(size[rx] > size[ry]) swap(rx, ry);
        par[rx] = ry;
        size[ry] += size[rx];
    }

    bool same(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
};


// weight[x]箭頭一律由parent -> x (diff = 後減前)
struct UnionFindW{
    vector<int> par;
    vector<int> size;
    vector<int> diff_weight;
    UnionFindW(int N) : par(N), size(N, 1), diff_weight(N) {
        for(int i=0;i<N;i++) par[i] = i;
    }
    int find(int x){
        if(par[x] == x) return x;
        else{
            int px = find(par[x]);
            // par[x] -> x的weight改成px -> x, 就加上px -> par[x]就好了
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = px;
        }
    }
    int weight(int x){
        find(x);
        return diff_weight[x];
    }
    int diff(int x, int y){
        assert(find(x) == find(y));
        // y - x
        return diff_weight[y] - diff_weight[x];
    }
    // weight[y] - weight[x] = w, x -> y = w
    // 轉換為px -> py, 加px -> x, y -> py, 就是 + weight[x] - weight[y]
    bool unite(int x, int y, int w){
        w += weight(x), w -= weight(y);
        x = find(x), y = find(y);
        if(x == y) return weight(y) - weight(x) == w;
        if(size[x] < size[y]) swap(x, y), w = -w;
        par[y] = x;
        size[x] += size[y];
        diff_weight[y] = w;
        return true;
    }
};

struct UnionFindLn {
    vector<int> par;
    vector<int> size;
    UnionFindLn(int N, vc<ll> a) : par(N), size(N){
        for(int i = 0; i < N; i++) par[i] = i, size[i] = 1;
    }
    int find(int x) {
      while(x != par[x]){
        x = par[x] = par[par[x]];
      }
      return x;
    }
    inline int get_leftmost_in_group(int x){
      int lx = find(x);
      return lx;
    }
    inline int get_rightmost_in_group(int x){
      int lx = find(x);
      return lx + size[lx] - 1;
    }
    inline int get_rightmost_in_left_group(int x){
      return get_leftmost_in_group(x) - 1;
    }
    inline int get_leftmost_in_right_group(int x){
      return get_rightmost_in_group(x) + 1;
    }
    array<int, 2> get_left_right(int x){ // not tested
      int lx = find(x);
      return {lx, lx + size[lx] - 1};
    }
    bool unite(int left, int right) {
        int lleft = find(left);
        int lright = find(right);
        if(lleft > lright) swap(lleft, lright);
        if (lleft == lright) return false;
        size[lleft] += size[lright];
        par[lright] = lleft;
        return true;
    }
    bool same(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
};