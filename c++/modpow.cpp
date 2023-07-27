#ifdef fixMOD
template<int MOD>
struct mint {
  unsigned x;
  vector<mint<MOD>> Comb;
  vector<mint<MOD>> Perm;
  vector<mint<MOD>> Fact;
  mint() : x(0) { }
  mint(signed sig) : x(((sig)%MOD+MOD)%MOD) {}
  void setComb(int n){
      /* Usage: 
            mint<MOD> Comb;
            Comb.setComb(12);
            F0R(i, 13) cout<<Comb.Comb[i]<<endl;
      */
      mint<MOD> c0 = 1;

      for(int i=0;i<=n;i++){
          Comb.push_back(c0);
          c0 *= (n-i);
          c0 /= (i+1);
      }
  }
  void setPerm(int n){
      /* Usage: 
            mint<MOD> Perm;
            Perm.setPerm(12);
            F0R(i, 13) cout<<Perm.Perm[i]<<endl;
      */
      mint<MOD> p0 = 1;
      for(int i=0;i<=n;i++){
          Perm.push_back(p0);
          p0 *= (n-i);
      }
  }
  void setFact(int n){
      /* Usage: 
            mint<MOD> Fact;
            Fact.setFact(12);
            F0R(i, 13) cout<<Fact.Fact[i]<<endl;
      */
      mint<MOD> f0 = 1;
      for(int i=1;i<=n;i++){
          Fact.push_back(f0);
          f0 *= i;
      }
  }
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
typedef mint<998244353> mint93;
#else
struct mint {
  unsigned x;
  ll MOD;
  vector<mint> Comb;
  vector<mint> Perm;
  vector<mint> Fact;
  mint(ll mod) : x(0), MOD(mod) { }
  mint(signed sig, ll mod) : x(((sig)%MOD+MOD)%MOD), MOD(mod) {}
  mint(signed long long sig, ll mod) : x(((sig)%MOD+MOD)%MOD), MOD(mod) { }
  void setComb(int n){
      /* Usage: 
            mint<MOD> Comb;
            Comb.setComb(12);
            F0R(i, 13) cout<<Comb.Comb[i]<<endl;
      */
      mint c0 = 1;

      for(int i=0;i<=n;i++){
          Comb.push_back(c0);
          c0 *= (n-i);
          c0 /= (i+1);
      }
  }
  void setPerm(int n){
      /* Usage: 
            mint<MOD> Perm;
            Perm.setPerm(12);
            F0R(i, 13) cout<<Perm.Perm[i]<<endl;
      */
      mint p0 = 1;
      for(int i=0;i<=n;i++){
          Perm.push_back(p0);
          p0 *= (n-i);
      }
  }
  void setFact(int n){
      /* Usage: 
            mint<MOD> Fact;
            Fact.setFact(12);
            F0R(i, 13) cout<<Fact.Fact[i]<<endl;
      */
      mint f0 = 1;
      for(int i=1;i<=n;i++){
          Fact.push_back(f0);
          f0 *= i;
      }
  }
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
#endif