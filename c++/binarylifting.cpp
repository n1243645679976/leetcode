
namespace BinaryLifting{
  const int N = 20; // 1<<20
  template<typename T>
  class BinaryLifting{
    vector<vector<T>> bl;
    vector<vector<T>> mi;
  public:
    BinaryLifting(vector<T> next){
      bl.resize(N+1);
      mi.resize(N+1);
      bl[0] = next;
      mi[0] = next;
      for(int i=1;i<N+1;i++){
        bl[i].resize(next.size());
        mi[i].resize(next.size());
        for(int j=0;j<next.size();j++){
          bl[i][j] = bl[i-1][bl[i-1][j]];
          mi[i][j] = min(mi[i-1][j], mi[i-1][bl[i-1][j]]);
        }
      }
    }
    T get(int ma_step, int ind, T prev){
      int now_step = 0;
      T mi_now = numeric_limits<T>::max();
      for(int i=N;i>=0;i--){
        if((now_step + (1<<i)) > ma_step) continue;
        if(mi[i][ind] < prev) continue;
        now_step += (1<<i);
        mi_now = min(mi_now, mi[i][ind]);
      }
      return mi_now;
    }
  };
}