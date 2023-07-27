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

// __int128
ostream& operator<<(ostream& a, __int128 out){if(out < 0) {a<<"-"; a << -out;} else {if(out > 9) a<<out/10; a<< int(out%10);} return a;}
istream& operator>>(istream& a, __int128& out){string l; cin>>l; trav(l) out *= 10, out += l - 48; return a;}
__int128 max(__int128 a, __int128 b){
  if(a > b) return a;
  else return b;
}
__int128 min(__int128 a, __int128 b){
  if(a < b) return a;
  else return b;
}

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(0,LLONG_MAX); //usage: long long xx = rnd(gen);


using i64 = long long;
#define MULTIINPUT
int solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n + 2);
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> q;
    i64 add = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (a[i] == k) {
            a[i] = 0;
        }
    }
    
    i64 ans = 0;
    int p = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] >= a[i - 1]) {
            q.push(a[i] - a[i - 1]);
        } else {
            q.push(0);
            q.push(k + a[i] - a[i - 1]);
        }
        
        ans += q.top();
        q.pop();
        
    }
    
    std::cout << ans << "\n";
    return -2;
}
 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int T = 1;
    #ifdef MULTIINPUT
	cin >> T;
    #endif
	while (T--) {
		int q = solve();
		if(q == 0) cout<<"No"<<endl;
		else if(q == 1) cout<<"Yes"<<endl;
	}
	return 0;
}