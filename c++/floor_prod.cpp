template <typename I, class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
Monoid floor_prod(I n, I m, I a, I b, Monoid x, Monoid y) {
    static auto monoid_pow = [&](Monoid m, int p) -> Monoid {
      Monoid res = e(), base = m;
      while(p){
        if(p & 1) res = op(res, base);
        base = op(base, base);
        p >>= 1;
      }
      return res;
    };
    x = op(x, monoid_pow(y, a / m));
    a %= m;
    const auto prefix_prod{monoid_pow(y, b / m)};
    b %= m;
    const auto y_max{a * n + b};
    if (y_max < m){
      auto f = op(prefix_prod, monoid_pow(x, n));
      return f;
    }
    auto f = op(op(op(prefix_prod, floor_prod<I, Monoid, op, e>(y_max / m - 1, a, m, m + a - b - 1, y, x)), y), monoid_pow(x, y_max % m / a));
    return f;
}
template <typename I, class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
pair<Monoid, string> floor_prod_dbg(I n, I m, I a, I b, Monoid x, Monoid y, Monoid init=e(), string sx="x", string sy="y") {
  static auto monoid_pow = [&](Monoid m, int p) -> Monoid {
    Monoid res = e(), base = m;
    while(p){
      if(p & 1) res = op(res, base);
      base = op(base, base);
      p >>= 1;
    }
    return res;
  };
  x = op(x, monoid_pow(y, a / m)); for(int i=0;i<a/m;i++) sx += sy;
  a %= m;
  
  const auto prefix_prod{op(init, monoid_pow(y, b / m))}; string spref = ""; for(int i=0;i<b/m;i++) spref += sy;
  b %= m;
  
  const auto y_max{a * n + b};
  if (y_max < m){
    auto f = op(prefix_prod, monoid_pow(x, n));
    for(int i=0;i<n;i++) spref += sx;
    return make_pair(f, spref);
  }
  auto [res, st] = floor_prod<I, Monoid, op, e>(y_max / m - 1, a, m, m + a - b - 1, y, x, e(), sy, sx);
  spref += st + sy; for(int i=0;i<y_max%m/a;i++) spref += sx;
  auto f = op(op(op(prefix_prod, res), y), monoid_pow(x, y_max % m / a));
  
  return make_pair(f, spref);
}