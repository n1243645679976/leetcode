template<typename T> class UnionFind{
public:
    unordered_map<T, T> parent;
    void unite(T a, T b);
    T find(T a);
};
template<typename T> void UnionFind<T>::unite(T a, T b){
    auto fa = find(a), fb = find(b);
    if(fa != fb){
        parent[fb] = parent[fa];
    }
}
template<typename T> T UnionFind<T>::find(T a){
    auto pa = parent.find(a);
    if(pa == parent.end()){
        parent[a] = a;
        return parent[a];
    }
    if(a == parent[a]){
        return a;
    }
    else{
        parent[a] = find(parent[a]);
        return parent[a];
    }
}

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
