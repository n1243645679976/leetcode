template<typename T>
int duval(int n, const T &s) {
  assert(n >= 1);
  int i = 0, ans = 0;
  vector<T> f;
  while (i < n) {
    ans = i;
    int j = i + 1, k = i;
    while (j < n + n && !(s[j % n] < s[k % n])) {
      if (s[k % n] < s[j % n]) {
        k = i;
      } else {
        k++;
      }
      j++;
    }
    while (i <= k) {
        f.push_back({});
        for(int ii=0;i+ii < n && ii<j-k;ii++) f.back().push_back(s[ii+i]);
      i += j - k;
    }
  }
  if(f.back().size() == 0) f.pop_back();
  // f -> lyndon representation
  // ans -> minimum start point, try rotate(s.begin(), s.begin() + ans, s.end());
  return ans;
}