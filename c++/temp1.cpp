#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ", "; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? ", " : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
void _println() {}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
template <typename T, typename... V>
void _println(T t, V... v) {__print(t); if (sizeof...(v)) cout << " "; _println(v...);}
#define DEBUG
#ifdef DEBUG
#define dbg(x...) cout << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cout << "\e[39m" << endl;
#define print(x...) _println(x); cout << endl;
#else
#define dbg(x...)
#endif

#define nl endl
#define elif else if
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define all(a) a.begin(), a.end()
#define trav(b) for(auto& b:b)
#define between(x, n) x < n && x >= 0
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define FORr(i, a, b) for(int i=b-1;i>=a;i--)
#define F1R(i, a) for(int i=1;i<=a;i++)
#define F0R(i, a) for(int i=0;i<a;i++)
#define F0Rr(i, a) for(int i=a-1;i>=0;i--)
#define gsz(a, b) int a = b.size();
#define glen(a, b) int a = b.length();
#define ckmax(a, b) a < b ? a = b: 0
#define smin(a, b) a = min(a, b)
#define gmax(a, b, c, d) tie(a,c) = d>c ? tie(b,d):tie(a,c)
#define gmin(a, b, c, d) tie(a,c) = d<c ? tie(b,d):tie(a,c)
#define sortkey(t, a) [=](t b, t c){return a(b) < a(c);} // sortkey(key)
#define enumerate(i, n, a) for(int i=0,n=a[i];i<a.size();i++,n=i<a.size()?a[i]:-1)
#define sgn(a) ((a>0) - (a<0))
#define Counter(t, a, b) map<t, int> a; trav(n, b) a[n]++;
#define mod17 1000000007
#define C15 100005
#define C16 1000006
#define C17 10000007
#define OR std::logical_or{}
#define AND std::logical_and{}
#define PLUS std::plus{}
#define pairwise(a, b, c, d) transform_reduce(a.begin(), a.end()-1, a.begin()+1, b, c, d) 
#define myrange(c, n) vector<int> c(n); F0R(i, n) c[i] = i;
#define POPCNT(x) __builtin_popcount(x)
#define POPCNTLL(x) __builtin_popcountll(x)
#define BITS(x) (x == 0 ? 0 : 31 - __builtin_clz(x))
#define coutf(a) cout<<a<<endl; cout.flush();
const int dirs[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; // use dirs[:4] for 4 dir

ostream& operator<<(ostream& a, __int128 out){if(out < 0) {a<<"-"; a << -out;} else {if(out > 9) a<<out/10; a<< int(out%10);} return a;}

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(0,LLONG_MAX); //usage: long long xx = rnd(gen);
template<int MOD>
struct ModInt {
  unsigned x;
  vector<ModInt<MOD>> Comb;
  vector<ModInt<MOD>> Perm;
  vector<ModInt<MOD>> Fact;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(((sig)%MOD+MOD)%MOD) {}
  void setComb(int n){
      ModInt<MOD> c0 = 1;

      for(int i=0;i<=n;i++){
          Comb.push_back(c0);
          c0 *= (n-i);
          c0 /= (i+1);
      }
  }
  void setPerm(int n){
      ModInt<MOD> p0 = 1;
      for(int i=0;i<=n;i++){
          Perm.push_back(p0);
          p0 *= (n-i);
      }
  }
  void setFact(int n){
      ModInt<MOD> f0 = 1;
      for(int i=1;i<=n;i++){
          Fact.push_back(f0);
          f0 *= i;
      }
  }
  ModInt(signed long long sig) : x(((sig)%MOD+MOD)%MOD) { }
  int get() const { return (int)x; }
  ModInt pow(ll p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};
typedef ModInt<1000000007> mint17;    
typedef ModInt<998244353> mint93;
class BIT{
public:
    int _max, _min;
    vector<int> c;
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
    int query(int i){
        int ans = 0;
        i += 2 + _min;
        while(i > 0){
            ans += c[i];
            i -= i & (-i);
        }
        return ans;
    }
};
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


int solve(){
  int n; cin>>n;
  vi a(n); trav(a) cin>>a;
  vi b(n); trav(b) cin>>b;
  vi count(3);
  
  F0R(i, n){
    set<pair<int, int>> r;
    int aa = a[i], bb = b[i];
    if(aa == 0 && bb == 0) {
      count[0]++, count[1]++, count[2]++;
      continue;
    }
    while(aa != 0 && bb != 0 && aa != bb){
      if(aa >= bb * 2) {aa %= bb * 2; continue;}
      if(bb >= aa * 2) {bb %= aa * 2; continue;}
      if(r.count({aa, bb})) return false;
      r.insert({aa, bb});
      if(aa > bb) aa = 2 * bb - aa;
      else bb = 2 * aa - bb;
    }
    if(aa == 0) count[0] += 1;
    else if(bb == 0) count[1] += 1;
    else count[2] += 1;
  }
  F0R(i, 3) if(count[i] == n) return true;
  return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) {
		int q = solve();
		if(q == 0) cout<<"No"<<endl;
		else if(q == 1) cout<<"Yes"<<endl;
	}
	return 0;
}