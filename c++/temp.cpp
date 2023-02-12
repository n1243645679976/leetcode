#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ll long long
#include<iostream>
using namespace std;
#define mod 998244353 
#define N 1000005
 
template<int MOD>
struct ModInt {
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(sig) {  }
  ModInt(signed long long sig) : x(sig%MOD) { }
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
typedef ModInt<998244353> mint;
 
mint a[N], b[N], c[N], d[N];
void answer(){
    signed ll n;
    vector<mint> vll;
    int d = 0;
    string s1, s2;
    cin>>n;
    cin>>s1>>s2;
    for(int i=0;i<n;i++){
        d += s1[i] != s2[i];
    }
    vll.push_back(0);
    vll.push_back(mint(2).pow(n) - 1);
    for(int i=2;i<=d;i++){
        
        mint c = ((vll[i-1] * n - n) - vll[i-2] * (i-1)) / (n-i+1);
        vll.push_back(c);
    }
    cout<<vll[d]<<endl;

}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        answer();
    }
}