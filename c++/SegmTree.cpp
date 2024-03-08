namespace SegmTree{
  // https://raw.githubusercontent.com/bicsi/kactl/master/content/data-structures/SegmentTree.h
 
  /**
   * Author: Lucian Bicsi
   * Description: Very fast and quick segment tree.
   * Only useful for easy invariants. 0-indexed.
   * Range queries are half-open.
   */

  int op(int a, int b){
    return max(a, b);
    //return a+b;
  }
  struct SegmTree {
    vector<int> T; int n;
    SegmTree(int n) : T(2 * n, (int)-2e9), n(n) {}
    
    void Update(int pos, int val) {
      for (T[pos += n] = val; pos > 1; pos /= 2)
        T[pos / 2] = op(T[pos], T[pos ^ 1]);
    }
    
    int Query(int b, int e) {
      int res = -2e9;
      for (b += n, e += n; b < e; b /= 2, e /= 2) {
        if (b % 2) res = op(res, T[b++]);
        if (e % 2) res = op(res, T[--e]);
      }
      return res;
    }
  };
}