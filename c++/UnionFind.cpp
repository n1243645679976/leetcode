template<typename T> class UnionFind{
public:
    unordered_map<T, T> parent;
    unordered_map<T, int> size;
    void unite(T a, T b);
    T find(T a);
};
template<typename T> void UnionFind<T>::unite(T a, T b){
    auto fa = find(a), fb = find(b);
    if(fa != fb){
        parent[fb] = parent[fa];
        size[fa] += size[fb];
    }
}
template<typename T> T UnionFind<T>::find(T a){
    auto pa = parent.find(a);
    if(pa == parent.end()){
        parent[a] = a;
        size[a] = 1;
        return parent[a];
    }
    if(a == parent[a]){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
    }
}

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
        par[rx] = ry;
        size[ry] += size[rx];
    }

    bool same(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
};
struct UnionFindR {
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
        par[rx] = max(rx, ry);
        par[ry] = max(rx, ry);
        size[ry] += size[rx];
    }

    bool same(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
};