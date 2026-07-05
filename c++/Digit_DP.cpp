template<size_t NUM_STATE,
        typename OUTPUT_TYPE,
        array<int, NUM_STATE> (*e)(),
        array<int, NUM_STATE> (*next_state)(array<int, NUM_STATE>, int plz, int nlz, int d), 
        OUTPUT_TYPE (*cal_state)(array<int, NUM_STATE>),
        int maxdigit = 9>
class Digit_DP{
  using state_type = array<int, NUM_STATE>;
  const static int SZ = 13000000;
  const static int dbgSZ = 300;
  state_type dims;
  state_type offset;
  int alloffset;
  state_type tmpT[dbgSZ];
  vector<int> dbg_inds;
  OUTPUT_TYPE dp[SZ];
  bool seen[SZ];
  int tight_ind;
  int string_len;
  set<int> used_index;
public:
  Digit_DP(state_type _dims, int _string_len) : dims(_dims), string_len(_string_len) {
    offset[NUM_STATE-1] = _string_len * 4;
    for(int i=dims.size()-1;i>0;i--) offset[i-1] = offset[i] * dims[i];
    alloffset = offset[0] * dims[0];
  }
  int to_index(state_type& g, int tight, int lz, int ind){
    int index = 0;
    for(int i=0;i<NUM_STATE;i++) index += offset[i] * g[i];
    index += string_len * 2 * tight + string_len * lz + ind;
    used_index.insert(index);
    return index;
  }
  void clear(){
    for(auto ind:used_index) seen[ind] = 0; used_index.clear();
  }
  OUTPUT_TYPE run(string& s, state_type state = e(), int tight = 1, int lz = 1, int ind = 0, int dbg_ind=-1, int entry = 1){
    // ans of [0, s]
    if(entry) clear();
    if(ind == s.size()){
      if(tight && dbg_ind >= 0) tmpT[dbg_ind] = state;
      return cal_state(state);
    }
    int index = to_index(state, tight, lz, ind);
    if(seen[index]) return dp[index];
    int ma = tight ? s[ind] - 48 : maxdigit;
    OUTPUT_TYPE res = 0;
    for(int i=0;i<ma+1;i++){
      int ntight = tight && i == ma;
      int nlz = lz && i == 0;
      res += run(s, next_state(state, lz, nlz, i), ntight, nlz, ind+1, dbg_ind, 0);
    }
    dp[index] = res, seen[index] = 1;
    if(dbg_ind >= 0) dbg_inds.push_back(index);
    return res;
  }
  void debug(){
    // output 0 ~ 10, 0 ~ 100
    vector<int> tars = {10, 100};
    for(auto tar:tars){
      assert(tar < dbgSZ);
      int digit = 0, tmp = tar; while(tmp) tmp /= 10, digit++;
      vector<OUTPUT_TYPE> anss;
      for(int i=0;i<=tar;i++){
        auto si = to_string(i);
        while(si.size() < digit) si.insert(si.begin(), '0');
        anss.push_back(run(si, e(), 1, 1, 0, i));
        for(auto ind:dbg_inds) dp[ind] = 0, seen[ind] = 0;
        dbg_inds.clear();
      }
      for(int i=tar;i>=1;i--) anss[i] -= anss[i-1];
      for(int i=0;i<=tar;i++) {
        cout<<i<<":";
        for(int j=0;j<NUM_STATE;j++) cout<<",{"[j==0]<<tmpT[i][j];
        cout<<"}"<<" "<<anss[i]<<",\t"; 
        if(i % 5 == 4) cout<<endl;
      }
      cout<<endl;
    }
  }
};