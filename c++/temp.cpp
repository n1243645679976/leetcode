#include <bits/stdc++.h>
using namespace std;
#define ll long long

void print(){cout<<'\n';}

template<typename T>
void print(const T t)
{
    cout<<t<<endl;
}
template<typename T, typename ...TAIL>
void print(const T &t, TAIL... tail)
{
    cout<<t<<' ';
    print(tail...);
}
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
void answer(){  
    int n;
    map<int, map<int, long long>> counter;
    cin>>n;
    string s;
    long long  ans=0;
    for(int j=0;j<n;j++){
        cin>>s;
        int bit = 0;
        int count = 0, ls=s.length();
        for(int i=0;i<ls;i++){
            bit |= 1 << (s[i] - 97);
            count ^= 1 << (s[i] - 97);
        }
        // exclude "a" > 0
        int mask = 1<<26;
        mask--;
        for(int i=0;i<26;i++){
            if(!(bit & (1<<i))){
                counter[i][count] += 1;
                ans += counter[i][(count^mask) & ((~(1<<i)) & mask)];
            }
        }

    }
    print(ans);
}
int main(){ios::sync_with_stdio(false);
  cin.tie(0);
    int T;
    T=0;
    //T = 1;
    //cin>>T;
    for(int i=0;i<0;i++){
        answer();
    }
    answer();
}