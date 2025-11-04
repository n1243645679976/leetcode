template<int MOD>
struct mint {
  unsigned x;
  mint() : x(0) { }
  mint(signed sig) : x(((sig)%MOD+MOD)%MOD) {}
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
typedef mint<998244353> mint99;
template<typename T>
struct minthelper{
  vector<T> fact, ifact;
  vector<T> bernoulli;
  vector<T> A;
  void build_facts(int k){
    if(!fact.size()) fact.push_back(T(1)), ifact.push_back(T(1));
    while(k >= fact.size()) fact.push_back(fact.size() * fact.back()), ifact.push_back(ifact.back() / ifact.size());
  }
  // Akiyama–Tanigawa algorithm
  void build_bernoulli(int k) {
      if(k < bernoulli.size()) return ;
      bernoulli.resize(k+1); A.resize(k+1);
      for (int m = bernoulli.size(); m <= k; ++m) {
          A[m] = T(1) / T(m + 1);
          for (int j = m; j >= 1; --j)
              A[j - 1] = (A[j - 1] - A[j]) * T(j);
          bernoulli[m] = A[0];
      }
      prevnotused = k + 1;
  }
  T C(int a, int b){
    assert(a >= b);
    return fact[a] * ifact[b] * ifact[a - b];
  }
};