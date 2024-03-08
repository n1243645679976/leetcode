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
#define VEC(a, n) vc<ll> a(n); cin>>a;
#define VV(a, n, m) vc<vc<int>> a(n, vc<int>(m)); trav(a) cin>>a;
#define VVLL(a, n, m) vc<vc<ll>> a(n, vc<ll>(m)); trav(a) cin>>a;
#define ADJ(adj, n, m)  vc<vc<int>> adj(n+1); rep(i, 0, m) {auto [a, b] = getints<2>(); adj[a].pb(b); adj[b].pb(a);}
#define ADJ1(adj, n, m)  vc<vc<int>> adj(n+1); rep(i, 0, m) {auto [a, b] = getints<2>(); a--, b--; adj[a].pb(b); adj[b].pb(a);}
#define ADJW(adj, n, m) vc<vc<ints2>> adj(n+1); rep(i, 0, m) {auto [a, b, c] = getints<3>(); adj[a].pb({b, c}); adj[b].pb({a, c});}
#define ADJWLL(adj, n, m) vc<vc<lls2>> adj(n+1); rep(i, 0, m) {auto [a, b, c] = getlls<3>(); adj[a].pb({b, c}); adj[b].pb({a, c});}
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
// if you are attending ABC, try random methods like abc339_f
// using lst:
//   apply需要是對任何節點都正確，如prod出max(s[l:r])，操作是^1的話，並不保證該節點為s'[l:r] = max(s[l:r]) ^ 1
bool comp(lls2& a, lls2& b){
    ll g = gcd(a[1], b[1]);
    __int128 a1 = a[0] * b[1] / g;
    __int128 a2 = b[0] * a[1] / g;
    dbg(a[0], a[1], b[0], b[1], int(a1), int(a2));
    return (a1 > a2) - (a1 < a2);
}
int solve(){
    INT(n);
    VEC(a, n);
    vc<lls2> r; r.pb({-1, 1});
    vc<double> ans;
    per(i, n-1, -1){
        lls2 k{a[i], 1};
        while(comp(k, r.back()) <= 0){
            k += r.back(); r.pop_back();
        }
        ans.pb(1.*k[0]/k[1]);
        r.pb(k);
    }
    dbg(r)
    rep(i, 0, n){
        printf("%.8lf\n", ans[i]);
    }

    return -2;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
#ifdef DOT
	cin >> T;
#endif
	while (T--) {
		int q = solve();
		if(q == 0) cout<<"No"<<endl;
		else if(q == 1) cout<<"Yes"<<endl;
	}
	return 0;
}