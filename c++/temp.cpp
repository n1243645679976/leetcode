#pragma GCC optimize("O3")
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
#define vv(type, name, n, m) vector name(n, vector<type>(m));
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
#define rep(i, a, b) for(int i=(a);i<(b);i++)
#define per(i, a, b) for(int i=(a);i>(b);i--)
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
#define INT4(a, b, c, d) int a, b, c, d; cin>>a>>b>>c>>d;
#define LL(a) ll a; cin>>a;
#define LL2(a, b) ll a, b; cin>>a>>b;
#define LL3(a, b, c) ll a, b, c; cin>>a>>b>>c;
#define LL4(a, b, c, d) ll a, b, c, d; cin>>a>>b>>c>>d;
#define STR(a) string a; cin>>a;
#define VEC(a, n) vc<int> a(n); cin>>a;
#define VEC1(a, n) vc<int> a(n); rep(i, 0, n) cin>>a[i], a[i]--;
#define VECLL(a, n) vc<ll> a(n); cin>>a;
#define VECLL1(a, n) vc<ll> a(n); rep(i, 0, n) cin>>a[i], a[i]--;
#define VV(a, n, m) vc<vc<int>> a(n, vc<int>(m)); trav(a) cin>>a;
#define VVLL(a, n, m) vc<vc<ll>> a(n, vc<ll>(m)); trav(a) cin>>a;
#define ADJ(adj, n, m)  vc<vc<int>> adj(n+1); rep(i, 0, m) {auto [a, b] = getints<2>(); adj[a].pb(b); adj[b].pb(a);}
#define ADJ1(adj, n, m)  vc<vc<int>> adj(n+1); rep(i, 0, m) {auto [a, b] = getints<2>(); a--, b--; adj[a].pb(b); adj[b].pb(a);}
#define ADJW(adj, n, m) vc<vc<ints2>> adj(n+1); rep(i, 0, m) {auto [a, b, c] = getints<3>(); adj[a].pb({b, c}); adj[b].pb({a, c});}
#define ADJW1(adj, n, m) vc<vc<pair<int, int>>> adj(n+1); rep(i, 0, m) {int a, b, c; cin>>a>>b>>c; a--, b--; adj[a].pb(make_pair(b, c)); adj[b].pb(make_pair(a, c));}
#define ADJWLL(adj, n, m) vc<vc<lls2>> adj(n+1); rep(i, 0, m) {auto [a, b, c] = getlls<3>(); adj[a].pb({b, c}); adj[b].pb({a, c});}
#define ADJWLL1(adj, n, m) vc<vc<lls2>> adj(n+1); rep(i, 0, m) {auto [a, b, c] = getlls<3>(); a--, b--; adj[a].pb({b, c}); adj[b].pb({a, c});}
#define chmin(a, b) a = min(a, b)
#define trav2dir(di, dj, i, j, n, m) for(int sajdklf = 0, di = i + _2dirs[sajdklf][0], dj = j + _2dirs[sajdklf][1]; sajdklf < 2; sajdklf++, di = i + _2dirs[sajdklf][0], dj = j + _2dirs[sajdklf][1]) if(between(di, n) && between(dj, m))
#define trav4dir(di, dj, i, j, n, m) for(int sajdklf = 0, di = i + _4dirs[sajdklf][0], dj = j + _4dirs[sajdklf][1]; sajdklf < 4; sajdklf++, di = i + _4dirs[sajdklf][0], dj = j + _4dirs[sajdklf][1]) if(between(di, n) && between(dj, m))

const ints2 _8dirs[8] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ints2 _4dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 

template<typename U, std::size_t T> array<U, T> operator+(const array<U, T>& arr1, const array<U, T>& arr2) {array<U, T> result;for(int i = 0; i < T; ++i) result[i] = arr1[i] + arr2[i]; return result;}
template<typename U, std::size_t T> array<U, T> operator-(const array<U, T>& arr1, const array<U, T>& arr2) {array<U, T> result;for(int i = 0; i < T; ++i) result[i] = arr1[i] - arr2[i]; return result;}
template<typename U, std::size_t T> array<U, T> operator*(const array<U, T>& arr1, const array<U, T>& arr2) {array<U, T> result;for(int i = 0; i < T; ++i) result[i] = arr1[i] * arr2[i]; return result;}
template<typename U, std::size_t T> array<U, T> operator/(const array<U, T>& arr1, const array<U, T>& arr2) {array<U, T> result;for(int i = 0; i < T; ++i) assert(arr2[i] != 0), result[i] = arr1[i] / arr2[i]; return result;}
template<typename U, std::size_t T> array<U, T> operator+=(array<U, T>& arr1, const array<U, T>& arr2) {for(int i = 0; i < T; ++i) arr1[i] += arr2[i]; return arr1;}
template<typename U, std::size_t T> array<U, T> operator-=(array<U, T>& arr1, const array<U, T>& arr2) {for(int i = 0; i < T; ++i) arr1[i] -= arr2[i]; return arr1;}
template<typename U, std::size_t T> array<U, T> operator*=(array<U, T>& arr1, const array<U, T>& arr2) {for(int i = 0; i < T; ++i) arr1[i] *= arr2[i]; return arr1;}
template<typename U, std::size_t T> array<U, T> operator/=(array<U, T>& arr1, const array<U, T>& arr2) {for(int i = 0; i < T; ++i) assert(arr2[i] != 0), arr1[i] /= arr2[i]; return arr1;}
template<typename T> void print(vector<T>& c, int a=-1, int b=-1){if(a == -1) a = 0; if(b == -1) b = c.size(); for(int i=a;i<b;i++) cout<<c[i]<<" \n"[i==b-1];}
template<typename T> void print(T t, char c='\n'){cout<<t<<c;}
template<typename T> void print(T* a, T* b){while(a < b) print(*a, ' '), a++; cout<<endl;}
template<typename T> void print(T* a, int b, int c){for(int i=b;i<c;i++) cout<<a[i]<<" "; cout<<endl;}
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
ll triangle(ll up, ll down, ll step){assert((up-down) % step == 0); if(up > down) return 0; return (up+down) * ((down - up) / step + 1) / 2;}
vc<int> getints(int n){vc<int> res(n); trav(res) cin>>res; return res;}
vc<ll> getlls(int n){vc<ll> res(n); trav(res) cin>>res; return res;}
ll getint(){ll a; cin>>a; return a;}
ll pow(ll a, ll b){ll res = 1; while(b){if(b&1) res *= a; a *= a; b>>=1;} return res;}
ll pow(int a, int b){ll res = 1; while(b){if(b&1) res *= a; a *= a; b>>=1;} return res;}
void YES(){print("Yes");}
void NO(){print("No");}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<typename T>
class SortedList : public __gnu_pbds::tree<T, __gnu_pbds::null_type,
                  std::less<T>, __gnu_pbds::rb_tree_tag,
                  __gnu_pbds::tree_order_statistics_node_update> { // pack like SortedList in python

public:
  T operator[](int x){
    assert(0 <= x && x < this->size());
    return *this->find_by_order(x);
  }
  int bisect_left(T x){
    return this->order_of_key(x);
  }
  int bisect_right(T x){
    int ind = this->order_of_key(x);
    if(this->operator[](ind) == x) ind++;
    return ind;
  }
  // insert
  // erase
  // lower_bound
  // upper_bound
  // size
};

template<int MOD>
struct mint {
  unsigned x;
  mint() : x(0) { }
  mint(signed sig) : x(((sig)%MOD+MOD)%MOD) {}
  mint(signed long long sig) : x(((sig)%MOD+MOD)%MOD) { }
  int get() const { return (int)x; }
  mint pow(ll p) { mint res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  mint &operator+=(mint that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  mint &operator-=(mint that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  mint &operator*=(mint that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  mint &operator/=(mint that) { return (*this) *= that.pow(MOD - 2); }
 
  mint operator+(mint that) const { return mint(*this) += that; }
  mint operator-(mint that) const { return mint(*this) -= that; }
  mint operator*(mint that) const { return mint(*this) *= that; }
  mint operator/(mint that) const { return mint(*this) /= that; }
  bool operator<(mint that) const { return x < that.x; }
  friend ostream& operator<<(ostream &os, mint a) { os << a.x; return os; }
};
typedef mint<1000000007> mint17;
typedef mint<998244353> mint99;
int ff = 0;
 
class BIT{
public:
    int _max, _min;
    vector<ll> c;
    BIT(int __max, int __min = 0){
        _max = __max + 2 + __min;
        _min = __min; // serve as offset
        c.reserve(_max);
        for(int i = 0;i<_max;i++){
            c[i] = 0;
        }
    }
    void update(int i, int v){
        i += 2 + _min;
        while(i < _max){
            c[i] += v;
            i += i & (-i);
        }
    }
    ll query(int i){
        ll ans = 0;
        i += 2 + _min;
        while(i > 0){
            ans += c[i];
            i -= i & (-i);
        }
        return ans;
    }
};
bool check(vc<int>& a){
  set<int> g;
  rep(i, 0, a.size()-1){
    if(g.count(a[i] * a[i+1])) {dbg(a[i], a[i+1]); return false;}
    g.insert(a[i] * a[i+1]);
  }
  return true;

}
namespace prime{
  vc<int> ps(1, 2);
  void setprimes(int n){
    for(int i=3;i<n;i+=2){
      int flag = 0;
      for(auto p:ps){
        if(i % p == 0) {flag = 1;break;}
      }
      if(!flag) ps.pb(i);
    }
  }
}
int solve(){
    INT2(n, d)
    vc<ints3> xy(n);
    map<ints2, int> xy2i;
    rep(i, 0, n){
        INT2(a, b)
        xy[i] = {a, b, i+1};
        xy2i[{a, b}] = i+1;
    }
    
    for(auto [a, b, i]:xy){
        if(d % 4 == 0){ 
            if(xy2i.count({a + d/2, b - d/2}) && xy2i.count({a + d / 4 * 3, b + d / 4})){
                cout<<i<<" "<<xy2i[{a+d/2, b-d/2}]<<" "<<xy2i[{a+d/4*3, b+d/4}]<<endl;
            }
            if(xy2i.count({a + d/2, b + d/2}) && xy2i.count({a + d / 4 * 3, b - d / 4})){

        }
        if(d % 2 == 0) if(sxy.count({a + d, b}) && sxy.count({a + d/2, b + d/2}))

    }

    return -2;
}

const int DOT = 1;

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