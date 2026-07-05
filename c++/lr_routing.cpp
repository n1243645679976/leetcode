// !! not tested.
template<typename T>
vector<T> iter_points(vector<array<int, 2>>& points, auto lmm, auto lpp, auto rmm, auto rpp, auto get){
  // points : [p[0], p[1]]
  // (y / B) * x + n * B -> B = sqrt(xy / n);
  int maxx = -1, maxy = -1, minx = 1e9, miny = 1e9, n = points.size();
  for(int i=0;i<points.size();i++) 
    maxx = max(maxx, points[i][0]), minx = min(minx, points[i][0]), 
    maxy = max(maxy, points[i][1]), miny = min(miny, points[i][1]);
  int B = 1ll * sqrt((maxy - miny + 1) * (maxx - minx + 1) / n);
  if(B <= 0) B = 1;
  vector<array<int, 4>> ips; rep(i, 0, n) ips.push_back({points[i][1] / B, points[i][0], points[i][1], i});
  for(int i=0;i<n;i++) ips[i][1] = ips[i][0] % 2 ? -ips[i][1] : ips[i][1];
  sort(ips.begin(), ips.end());
  for(int i=0;i<n;i++) ips[i][1] = ips[i][0] % 2 ? -ips[i][1] : ips[i][1];
  // [nowl, nowr)
  int nowl = 0, nowr = 0;
  vector<T> ans(n);
  for(int indp=0;indp<n;indp++){
    auto [_, l, r, ind] = ips[indp]; 
    r++;
    dbg(l, r);
    while(nowr < r) rpp(nowr++);
    while(nowl > l) lmm(--nowl);
    while(nowr > r) rmm(--nowr);
    while(nowl < l) lpp(nowl++);
    ans[ind] = get();
  }
  return ans;
}

int solve() {
  vc<ints2> ps = {{0, 15}, {1, 11}, {2, 10}, {3, 13}, {4, 5}, {6, 8}, {5, 5}, {7, 12}};
  ints3 res = {0, 0, 0};
  dbg(res);
  auto add = [&](int l){res[0]++, res[1] += l, res[2] += l*l;};
  auto rem = [&](int l){res[0]--, res[1] -= l, res[2] -= l*l;};
  auto get = [&](){return res;};
  auto ans = iter_points<ints3>(ps, add, rem, rem, add, get);
  dbg(ans);
  return -2;
}