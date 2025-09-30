// https://atcoder.jp/contests/abc425/submissions/69679812
long long egcd(long long a, long long b, long long& resa, long long& resb){
    // return resa * a + resb * b = gcd
    if(a == 0){
        resa = 0, resb = 1; return b;
    }
    long long x1 = 0, y1 = 0;
    long long gcd = egcd(b%a, a, x1, y1);
    resa = y1 - (b/a) * x1;
    resb = x1;
    return gcd;
}
struct Barret{
  uint32_t m;
  uint64_t im;
  Barret(uint32_t _mod) : m(_mod), im(uint64_t(-1) / m + 1) {}
  constexpr uint32_t mod() const {return m;}
  constexpr uint32_t mul(uint32_t a, uint32_t b) const {
    uint64_t z = a;
    z *= b;
    uint64_t x = uint64_t(((__uint128_t)(z) * im) >> 64);
    uint32_t v = uint32_t(z - x * m);
    if(m <= v) v += m;
    return v;
  }
};
template<uint32_t Id>
struct dmint {
  constexpr dmint() : x(0) {}
  constexpr dmint(unsigned long long _x) : x(_x % mod()) {}
  constexpr dmint(long long _x) { int v = _x % int(mod()); if(v < 0) v += mod(); x = v; }
  constexpr dmint(unsigned int _x) : x(_x % mod()) {}
  constexpr dmint(int _x) { int v = _x % int(mod()); if(v < 0) v += mod(); x = v; }
  constexpr uint32_t val() const {return x;}
  constexpr dmint operator-() const {return {x == 0 ? 0:mod() - x};}
  constexpr dmint inv() const {ll r1, r2; egcd(mod(), x, r1, r2); return dmint(r2);}
  constexpr dmint& operator*=(const dmint &that) {x = bt.mul(x, that.val()); return *this;}
  constexpr dmint& operator+=(const dmint &that) {x += that.val(); if(x >= mod()) x -= mod(); return *this;}
  constexpr dmint& operator-=(const dmint &that) {x -= that.val(); if(x >= mod()) x += mod(); return *this;}
  constexpr dmint& operator/=(const dmint &that) {*this *= that.inv(); return *this;}
  
  constexpr dmint operator+(dmint that) const { return dmint(*this) += that; }
  constexpr dmint operator-(dmint that) const { return dmint(*this) -= that; }
  constexpr dmint operator*(dmint that) const { return dmint(*this) *= that; }
  constexpr dmint operator/(dmint that) const { return dmint(*this) /= that; }
  friend constexpr std::ostream &operator<<(ostream &out, dmint &a) {out<<a.val(); return out;}

  static uint32_t mod(){return bt.mod();}
  constexpr static void setMod(uint32_t m){bt = m;}

  uint32_t x;
  static Barret bt;
};
template<uint32_t Id> Barret dmint<Id>::bt = 998244353;