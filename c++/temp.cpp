#include <bits/stdc++.h>
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
#define ints5 array<int, 5>
#define lls2 array<long long, 2>
#define lls3 array<long long, 3>
#define lls4 array<long long, 4>
#define lls5 array<long long, 5>
#define pb push_back
#define ppb pop_back
#define all(a) a.begin(), a.end()
#define trav(b) for(auto& b:b) 
#define MAX(a) (*max_element(all(a)))
#define MIN(a) (*min_element(all(a)))

#define between(x, n) (x < n && x >= 0)
#define between2(x, n, m) (between(x[0], n) && between(x[1], m))
#define rep(i, a, b) for(int i=(a);i<(b);i++)
#define per(i, a, b) for(int i=(a);i>(b);i--)
#define ee9 1000000000
#define ee18 1000000000000000000ll
#define popcount __builtin_popcount
#define len(a) ((int)(a.size()))
#define fullmask(a) ((1<<a)-1)
#define UNIQ(a) a.erase(unique(all(a)), a.end())
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
#define VV(type, a, n, m) vc<vc<type>> a(n, vc<type>(m)); trav(a) cin>>a;
#define ADJ(adj, n, m)  vc<vc<int>> adj(n+1); rep(i, 0, m) {auto [a, b] = getints<2>(); adj[a].pb(b); adj[b].pb(a);}
#define ADJ1(adj, n, m)  vc<vc<int>> adj(n+1); rep(i, 0, m) {int a, b; cin>>a; cin>>b; a--, b--; adj[a].pb(b); adj[b].pb(a);}
#define ADJW(adj, n, m) vc<vc<ints2>> adj(n+1); rep(i, 0, m) {auto [a, b, c] = getints<3>(); adj[a].pb({b, c}); adj[b].pb({a, c});}
#define ADJW1(adj, n, m) vc<vc<pair<int, int>>> adj(n+1); rep(i, 0, m) {int a, b, c; cin>>a>>b>>c; a--, b--; adj[a].pb(make_pair(b, c)); adj[b].pb(make_pair(a, c));}
#define ADJWLL(adj, n, m) vc<vc<lls2>> adj(n+1); rep(i, 0, m) {auto [a, b, c] = getlls<3>(); adj[a].pb({b, c}); adj[b].pb({a, c});}
#define ADJWLL1(adj, n, m) vc<vc<lls2>> adj(n+1); rep(i, 0, m) {auto [a, b, c] = getlls<3>(); a--, b--; adj[a].pb({b, c}); adj[b].pb({a, c});}
#define trav2dir(di, dj, i, j, n, m) for(int sajdklf = 0, di = i + _2dirs[sajdklf][0], dj = j + _2dirs[sajdklf][1]; sajdklf < 2; sajdklf++, di = i + _2dirs[sajdklf][0], dj = j + _2dirs[sajdklf][1]) if(between(di, n) && between(dj, m))
#define trav4dir(di, dj, i, j, n, m) for(int sajdklf = 0, di = i + _4dirs[sajdklf][0], dj = j + _4dirs[sajdklf][1]; sajdklf < 4; sajdklf++, di = i + _4dirs[sajdklf][0], dj = j + _4dirs[sajdklf][1]) if(between(di, n) && between(dj, m))
#define trav8dir(di, dj, i, j, n, m) for(int sajdklf = 0, di = i + _8dirs[sajdklf][0], dj = j + _8dirs[sajdklf][1]; sajdklf < 8; sajdklf++, di = i + _8dirs[sajdklf][0], dj = j + _8dirs[sajdklf][1]) if(between(di, n) && between(dj, m))

const ints2 _8dirs[9] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {-1, 0}};
const ints2 _4dirs[5] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-100, -100}}; 

template<typename U, std::size_t T> ostream& operator<<(ostream& a, array<U, T>& arr){if(T == 0) {a<<"{}"; return a;} a<<"{"<<arr[0]; for(int i=1;i<T;i++) a<<", "<<arr[i]; a<<"}"; return a;}

template<typename T> void print(vector<T>& c, int a=-1, int b=-1){if(a == -1) a = 0; if(b == -1) b = c.size(); for(int i=a;i<b;i++) cout<<c[i]<<" \n"[i==b-1];}
template<typename T> void print(T t, char c='\n'){cout<<t<<c;}
template<typename T> void print(T* a, T* b){while(a < b) print(*a, ' '), a++; cout<<endl;}
template<typename T> void print(T* a, int b, int c){for(int i=b;i<c;i++) cout<<a[i]<<" "; cout<<endl;}
template<typename T> void printmat(vc<vc<T>> a){trav(a) print(a);}
template<typename T> ostream& operator<<(ostream& a, vector<T>& arr){for(int i=0;i<arr.size();i++) a<<arr[i]<<" "; return a;}
string to_string(__int128 out){string ans; int neg = 0; if(out < 0) {neg = 1; out = -out;} while(out) ans.push_back(static_cast<char>(out % 10) + '0'), out /= 10; if(neg) ans.push_back('-'); reverse(ans.begin(), ans.end()); if(!ans.size()) ans.push_back('0'); return ans;}
ostream& operator<<(ostream& a, __int128 out){if(out < 0) {a<<"-"; a << -out;} else {if(out > 9) a<<out/10; a<< int(out%10);} return a;}

int strcmp(string& a, string& b, int& ia, int& ib){auto res = memcmp(&a[ia], &b[ib], min(a.size()-ia, b.size()-ib));if(res != 0) return res;return (a.size() - ia > b.size() - ib) - (b.size() - ib > a.size() - ia);}
template<typename T> void gmin(T& a, T b){a = min(a, b);}
template<typename T> void gmax(T& a, T b){a = max(a, b);}
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(0,LLONG_MAX); //usage: long long xx = rnd(gen);
template<typename T, std::size_t N> istream& operator>>(istream& a, array<T, N>& in){rep(i, 0, N) a>>in[i]; return a;}
template<typename T> istream& operator>>(istream& a, vector<T>& in){for(auto& gin:in) a>>gin; return a;}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace chh{
  template <size_t T> 
  class bitset : public std::bitset<T> {
    public:using std::bitset<T>::bitset;
    bool operator<(const bitset& other) const {
      return (*this & ~other)._Find_first() < (other & ~*this)._Find_first();
    }
  };
  template<typename T>
  class multiset : public __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>{
    public:
      auto operator[](int ind){
        assert(0 <= ind && ind < this->size());
        return *this->find_by_order(ind);
      }
      inline auto lower_bound(T a){
        return __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>::lower_bound(a--);
      }
      // iterator find_by_order(int k) ;
      // int order_of_key(T a) ;
      array<int, 2> index(T a){return {int(this->order_of_key(a)), int(this->order_of_key(++a))};} // [i, j)
  };
  template<typename T>
  class set : public __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>{
    public:
      auto operator[](int ind){
        assert(0 <= ind && ind < this->size());
        return *this->find_by_order(ind);
      }
      // iterator find_by_order(int k) ;
      // int order_of_key(T a) ;
      int index(T a){return order_of_key(a);}
  };
}

template<int MOD>
struct mint { 
  unsigned x;
  mint() : x(0) { }
  mint(signed sig) : x(((sig)%MOD+MOD)%MOD) {}
  mint(signed long long sig) : x(((sig)%MOD+MOD)%MOD) { }
  int val() const { return (int)x; }
  mint pow(long long p) { mint res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  mint &operator+=(mint that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  mint &operator-=(mint that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  mint &operator*=(mint that) { x = static_cast<unsigned>((unsigned long long)x * that.x % MOD); return *this; }
  mint &operator/=(mint that) { return (*this) *= that.pow(MOD - 2); }
 
  mint operator+(mint that) const { return mint(*this) += that; }
  mint operator-(mint that) const { return mint(*this) -= that; }
  mint operator*(mint that) const { return mint(*this) *= that; }
  mint operator/(mint that) const { return mint(*this) /= that; }
  bool operator<(mint that) const { return x < that.x; }
  
  friend mint operator+(int lhs, mint rhs) {return rhs + lhs;}
  friend mint operator-(int lhs, mint rhs) {return mint(lhs) - rhs;}
  friend mint operator*(int lhs, mint rhs) {return rhs * lhs;}
  friend mint operator/(int lhs, mint rhs) {return mint(lhs) / rhs;}

  friend ostream& operator<<(ostream &os, mint a) { os << a.x; return os; }
};
typedef mint<1000000007> mint17;
typedef mint<998244353> mint99;
#define ee16 10000000000000000ll
// from https://atcoder.jp/contests/abc412/submissions/67136219
long long int_next_comb(long long comb) {
  // next_combination of k bits in comb -> starts with comb = (1 << k) - 1
  // ends with while(comb < (1 << maxbits))
  long long x = comb & -comb, y = comb + x;
  return ((comb & ~y) / x >> 1) | y;
}
ll __mg(ll x){return __lg(x ^ (x-1));}
// 直接DP或許會過!?!?!?
// 直接做或許會過!?!?!?
class Node{
public:
  ints2 child = {0, 0};
};
int solve() {
  vector<ints3> nodes(1);
  INT2(n, m)
  VEC(a, n)
  sort(all(a)); UNIQ(a);
  auto add = [&](int a){
    int nowind = 0;
    per(i, 30, -1){
      if(nodes[nowind][a >> i & 1] == 0) {
        nodes[nowind][a >> i & 1] = nodes.size();
        nodes.push_back({0, 0, 0});
      }
      nodes[nowind][2]++;
      nowind = nodes[nowind][a >> i & 1];
    }
  };
  rep(i, 0, a.size()){
    add(a[i]);
  }
  vc<int> ff;
  auto dfs = [&](auto& dfs, ll ma, int bit, int nodeind) -> ll {
    if(bit == -1){
      return 0;
    }
    assert(nodes[nodeind][2] != 0);
    
    ll ans = 0;
    int go0 = nodes[nodeind][0], go1 = nodes[nodeind][1];
    ll cnt0 = min((1ll << bit), ma + 1), cnt1 = max(-1ll, ma + 1 - cnt0);
    ints3 param0 = {cnt0-1, bit-1, go0}, param1 = {cnt1-1, bit-1, go1};
    if(go0 == 0) ans += (1ll << bit) * cnt0, param0[2] = go1;
    if(go1 == 0) ans += (1ll << bit) * cnt1, param1[2] = go0;
    if(param0 == param1) {
      ll tmp = dfs(dfs, param0[0], param0[1], param0[2]);
      return ans + 2 * tmp;
    }
    else{
      ll tmp = dfs(dfs, param0[0], param0[1], param0[2]);
      if(param1[0] != -1) tmp += dfs(dfs, param1[0], param1[1], param1[2]);
      return ans + tmp;
    }
    
  };
  cout<<dfs(dfs, m-1, 30, 0)<<endl;
  return -2;
}

const int DOT = 0;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1; 
  if(DOT) cin >> T;
	while (T--) {
		int q = solve();
		if(q == 0) cout<<"No"<<endl;
		else if(q == 1) cout<<"Yes"<<endl;
    else if(q == -1) cout<<-1<<endl;
	}
	return 0;
}