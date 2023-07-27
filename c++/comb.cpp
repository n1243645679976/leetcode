struct ModInt {
  unsigned  x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(((sig)%MOD+MOD)%MOD) {  }
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
template<int MOD = INT_MAX>
struct Combn {
	ModInt<MOD> mint = 1;
	int n, i;
	Combn(int nn){
		n = nn+1;
		i = nn;
	}
	ModInt<MOD> next(){
		// C(n, 0) -> C(n, 1) -> C(n, 2) ..., a total of n+1 outcomes.
		auto temp = mint;
		mint *= i;
		mint /= (n-i);
		i--;
		return temp;
	}
};
typedef ModInt<1000000007> mint;
typedef Combn<1000000007> Comb;