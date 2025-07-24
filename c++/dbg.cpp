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
template<typename T, const long long unsigned int n>
void __print(const array<T, n> &x){int f = 0; cout << '{'; for (int i=0;i<n;i++) cout << (i ? ", " : ""), __print(x[i]); cout << "}";}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ", "; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? ", " : ""), __print(i); cout << "}";}
template<typename T, typename V>
void __print(map<T, V>& x) {int f = 0; cout << '{'; for(auto& x:x) {cout << (f++ ? ", " : ""); __print(x.first); cout << " : "; __print(x.second);} cout << '}';}
void _print() {cout << "]\n";}
void _println() {}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
template <typename T, typename... V>
void _println(T t, V... v) {__print(t); if (sizeof...(v)) cout << " "; _println(v...);}
#define dbg(x...) cout << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cout << "\e[39m" << endl;