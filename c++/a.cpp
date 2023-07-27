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
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define DEBUG
#ifdef DEBUG
#define dbg(x...) cout << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cout << "\e[39m" << endl;
#else
#define dbg(x...)
#endif
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pb emplace_back
#define ppb pop_back
#define all(a) a.begin(), a.end()
#define trav(a, b) for(auto a:b)
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define F0R(i, a) for(int i=0;i<a;i++)
#define F0Rr(i, a) for(int i=a-1;i>=0;i--)
#define gsz(a, b) int a = b.size();
#define glen(a, b) int a = b.length();
#define smax(a, b) a = max(a, b)
#define smin(a, b) a = min(a, b)
#define gmax(a, b, c, d) tie(a,c) = d>c ? tie(b,d):tie(a,c)
#define gmin(a, b, c, d) tie(a,c) = d<c ? tie(b,d):tie(a,c)
#define sortkey(a) [](pii b, pii c){return a(b) < a(c);} // sortkey(key)
#define enumerate(i, n, a, la) for(int i=0,n=a[i];i<la;i++,n=a[i])
#define sgn(a) ((a>0) - (a<0))
#define mod17 1000000007
template<typename T>
vector<T> vslice(vector<T> c, int start, int end, int stride){
    vector<T> r;
    for(int i=start;i<end;i+=stride) r.pb(c[i]);
    return r;
}
string vslice(string c, int start, int end, int stride){
    vector<char> r(all(c)), q = vslice(r, start, end, stride);
    return string(all(q));
}
hash_map g;
int main(){
}