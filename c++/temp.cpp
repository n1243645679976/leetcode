#include<bits/stdc++.h>
#include <cassert>
using namespace std;
#ifdef LOCAL
#include "dbg.cpp"
#else
#define dbg(x...)
#endif
#define ll long long
#define vc vector
#define ints2 array<int, 2>
#define ints3 array<int, 3>
#define ints4 array<int, 4>
#define lls2 array<long long, 2>
#define lls3 array<long long, 3>
#define lls4 array<long long, 4>
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define all(a) a.begin(), a.end()
#define sz(a) (int(a.size()))
#define trav(b) for(auto& b:b)
#define between(x, n) (((x) < n) && ((x) >= 0))
#define between2(x, n, m) (between(x[0], n) && between(x[1], m))
#define rep(i, a, b) for(int i=a;i<b;i++)
#define per(i, a, b) for(int i=a;i>b;i--)
#define coutf(a) cout<<a<<endl; cout.flush();
#define inf 2000000000
#define infll 4000000000000000000ll
#define mod17 1000000007
#define mod99 998244353
#define vcint vc<int>
#define vcll vc<ll>
#define popcount __builtin_popcount
#define ACC accumulate
#define SORT(a) sort(all(a))
#define UNIQ(a) a.erase(unique(all(a)), a.end())
#define ERASE(a, b) a.erase(a.find(b))
#define INSERT(a, b) a.insert(b)
#define ZERO(a) fill(all(a), 0);
#define ZERO2(a) trav(a) fill(all(a), 0);
#define INT(a) int a; cin>>a;
#define INT2(a, b) int a, b; cin>>a>>b;
#define INT3(a, b, c) int a, b, c; cin>>a>>b>>c;
#define LL(a) ll a; cin>>a;
#define LL2(a, b) ll a, b; cin>>a>>b;
#define LL3(a, b, c) ll a, b, c; cin>>a>>b>>c;
#define STR(a) string a; cin>>a;
#define VEC(a, n) vc<int> a(n); cin>>a;
#define VECLL(a, n) vc<ll> a(n); cin>>a;
#define VV(a, n, m) vc<vc<int>> a(n, vc<int>(m)); trav(a) cin>>a;
#define VVLL(a, n, m) vc<vc<ll>> a(n, vc<ll>(m)); trav(a) cin>>a;
#define ADJ(adj, n, m)  vc<vc<int>> adj(n+1); rep(i, 0, m) {auto [a, b] = getints<2>(); adj[a].pb(b); adj[b].pb(a);}
#define ADJ1(adj, n, m)  vc<vc<int>> adj(n+1); rep(i, 0, m) {auto [a, b] = getints<2>(); a--, b--; adj[a].pb(b); adj[b].pb(a);}
#define ADJW(adj, n, m) vc<vc<ints2>> adj(n+1); rep(i, 0, m) {auto [a, b, c] = getints<3>(); adj[a].pb({b, c}); adj[b].pb({a, c});}
#define ADJWLL(adj, n, m) vc<vc<lls2>> adj(n+1); rep(i, 0, m) {auto [a, b, c] = getlls<3>(); adj[a].pb({b, c}); adj[b].pb({a, c});}
#define chmin(a, b) a = min(a, b)
#define trav2dir(di, dj, i, j, n, m) for(int sajdklf = 0, di = i + _2dirs[sajdklf][0], dj = j + _2dirs[sajdklf][1]; sajdklf < 2; sajdklf++, di = i + _2dirs[sajdklf][0], dj = j + _2dirs[sajdklf][1]) if(between(di, n) && between(dj, m))

const ints2 _8dirs[8] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ints2 _4dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
const ints2 _2dirs[2] = {{0, 1}, {1, 0}}; 

template<typename U, std::size_t T> array<U, T> operator+(const array<U, T>& arr1, const array<U, T>& arr2) {array<U, T> result;for(int i = 0; i < T; ++i) result[i] = arr1[i] + arr2[i]; return result;}
template<typename U, std::size_t T> array<U, T> operator-(const array<U, T>& arr1, const array<U, T>& arr2) {array<U, T> result;for(int i = 0; i < T; ++i) result[i] = arr1[i] - arr2[i]; return result;}
template<typename U, std::size_t T> array<U, T> operator*(const array<U, T>& arr1, const array<U, T>& arr2) {array<U, T> result;for(int i = 0; i < T; ++i) result[i] = arr1[i] * arr2[i]; return result;}
template<typename U, std::size_t T> array<U, T> operator/(const array<U, T>& arr1, const array<U, T>& arr2) {array<U, T> result;for(int i = 0; i < T; ++i) assert(arr2[i] != 0), result[i] = arr1[i] / arr2[i]; return result;}
template<typename U, std::size_t T> array<U, T> operator+=(array<U, T>& arr1, const array<U, T>& arr2) {for(int i = 0; i < T; ++i) arr1[i] += arr2[i]; return arr1;}
template<typename U, std::size_t T> array<U, T> operator-=(array<U, T>& arr1, const array<U, T>& arr2) {for(int i = 0; i < T; ++i) arr1[i] -= arr2[i]; return arr1;}
template<typename U, std::size_t T> array<U, T> operator*=(array<U, T>& arr1, const array<U, T>& arr2) {for(int i = 0; i < T; ++i) arr1[i] *= arr2[i]; return arr1;}
template<typename U, std::size_t T> array<U, T> operator/=(array<U, T>& arr1, const array<U, T>& arr2) {for(int i = 0; i < T; ++i) assert(arr2[i] != 0), arr1[i] /= arr2[i]; return arr1;}
void print(vector<int>& c){for(int i=0;i<c.size();i++) cout<<c[i]<<" \n"[i==c.size()-1];}
template<typename T> void print(T t, char c='\n'){cout<<t<<c;}
template<typename T> void print(T* a, T* b){while(a < b) print(*a, ' '), a++; cout<<endl;}
template<typename T> void printmat(vc<vc<T>> a){trav(a) print(a);}
ostream& operator<<(ostream& a, __int128 out){if(out < 0) {a<<"-"; a << -out;} else {if(out > 9) a<<out/10; a<< int(out%10);} return a;}
int strcmp(string& a, string& b, int& ia, int& ib){auto res = memcmp(&a[ia], &b[ib], min(a.size()-ia, b.size()-ib));if(res != 0) return res;return (a.size() - ia > b.size() - ib) - (b.size() - ib > a.size() - ia);}
template<typename U, std::size_t T> ll get(array<U, T>& a, ll u){ll x=0; for(int i=0;i<T;i++) x *= u, x += a[i]; return x;}
template<typename T> void gmin(T& a, T b){a = min(a, b);}
template<typename T> void gmax(T& a, T b){a = max(a, b);}
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(0,LLONG_MAX); //usage: long long xx = rnd(gen);
template<int k> array<int, k> getints(){array<int, k> res; rep(i, 0, k) cin>>res[i]; return res;} 
template<int k> array<ll, k> getlls(){array<ll, k> res; rep(i, 0, k) cin>>res[i]; return res;}
template<typename T, std::size_t N> istream& operator>>(istream& a, array<T, N>& in){rep(i, 0, N) a>>in[i]; return a;}
template<typename T> istream& operator>>(istream& a, vector<T>& in){for(auto& gin:in) a>>gin; return a;}
vc<int> getints(int n){vc<int> res(n); trav(res) cin>>res; return res;}
vc<ll> getlls(int n){vc<ll> res(n); trav(res) cin>>res; return res;}
ll getint(){ll a; cin>>a; return a;}

ll pow(ll a, ll b){ll res = 1; while(b){if(b&1) res *= a; a *= a; b>>=1;} return res;}
ll pow(int a, int b){ll res = 1; while(b){if(b&1) res *= a; a *= a; b>>=1;} return res;}
void YES(){print("Yes");}
void NO(){print("No");}

const int DOT = 1;

class S{
	int m1;
	int m2;
}
template <class S, S (*op)(S, S), S (*e)()> struct segtree {

#endif

  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

int solve(){
    return -2;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
    if(DOT) cin >> T;
	while (T--) {
		int q = solve();
		if(q == 0) cout<<"No"<<endl;
		else if(q == 1) cout<<"Yes"<<endl;
	}
	return 0;
}