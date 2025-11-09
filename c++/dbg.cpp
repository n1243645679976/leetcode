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
template<typename T> void __print(T x) {cout<<x;}
template<typename T, size_t N>
void __print(const array<T, N> &a){cout<<"{"; for(int i=0;i<N;i++) cout<<(i == 0 ? "": ", ")<<a[i]; cout<<"}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ", "; __print(x.second); cout << '}';}
template<typename T>
void __print(const deque<T> &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? ", " : ""), __print(i); cout << "}";}
template<typename T>
void __print(const vector<T> &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? ", " : ""), __print(i); cout << "}";}
template<typename T, typename U>
void __print(const map<T, U> &x) {int f = 0; cout << '{'; for (auto [k, v]: x) {cout << (f++ ? ", " : ""), __print(k); cout<<':';  __print(v);} cout << "}";}
template<typename T>
void __print(vector<T> &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? ", " : ""), __print(i); cout << "}";}
template<typename T>
void __print(set<T> &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? ", " : ""), __print(i); cout << "}";}

template<typename T, typename U> void __print(map<T, U> &x){int f = 0; cout<<'{'; for(auto& [k, v]:x){cout << (f++ ? ", " : ""); __print(k); cout<<":"; __print(v);} cout<<"}";}
template<typename T, typename U> void __print(unordered_map<T, U> &x){int f = 0; cout<<'{'; for(auto& [k, v]:x){cout << (f++ ? ", " : ""); __print(k); cout<<":"; __print(v);} cout<<"}";}
void _print() {cout << "]\n";}
void _println() {}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
template <typename T, typename... V>
void _println(T t, V... v) {__print(t); if (sizeof...(v)) cout << " "; _println(v...);}
#define dbg(x...) cout << "\e[91m"<< __FILE__<<":"<<__LINE__ <<"," <<__func__<<" [" << #x << "] = ["; _print(x); cout << "\e[39m" << endl;    
