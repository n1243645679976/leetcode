// solve: https://atcoder.jp/contests/abc465/tasks/abc465_e
//   array<int, 3> e(){return {0, 0, 0};}
//   array<int, 3> next_state(array<int, 3> now, int ntight, int nlz, int d){
//     auto [mod, c3, dec] = now;
//     return {(mod+d)%3, c3 || (d == 3), nlz ? 0 : dec | (1 << d)};
//   }
//   mint99 cal_state(array<int, 3> now){
//     return (now[0] == 0) + (now[1] == 1) + (popcount(now[2]) == 3) == 1;
//   }
//   Digit_DP<3, mint998244353, e, next_state, cal_state> ddp(std::array<int,3>{3,2,1024}, 501);
//   cout<<ddp.run(s) - 1<<endl;

/*
  Digit_DP<NUM_STATE, OUTPUT_TYPE, e, next_state, cal_state, maxdigit> ddp(array<int, NUM_STATE> EACH_STATE_MAX_DIM, NUM_LENGTH);

  (max size of each state as array<int, N>, number_length)
  ddp.run(string num) to calculate 0 ~ num
  ddp.debug() output the state and output of each number from 0 to 10 and 0 to 100:
    0:{0,0,0} 1,    1:{1,0,2} 0,    2:{2,0,4} 0,    3:{0,1,8} 0,    4:{1,0,16} 0,
    5:{2,0,32} 0,   6:{0,0,64} 1,   7:{1,0,128} 0,  8:{2,0,256} 0,  9:{0,0,512} 1,
    10:{1,0,3} 0,
    0:{0,0,0} 1,    1:{1,0,2} 0,    2:{2,0,4} 0,    3:{0,1,8} 0,    4:{1,0,16} 0,
    5:{2,0,32} 0,   6:{0,0,64} 1,   7:{1,0,128} 0,  8:{2,0,256} 0,  9:{0,0,512} 1,
    10:{1,0,3} 0,   11:{2,0,2} 0,   12:{0,0,6} 1,   13:{1,1,10} 1,  14:{2,0,18} 0,
    15:{0,0,34} 1,  16:{1,0,66} 0,  17:{2,0,130} 0, 18:{0,0,258} 1, 19:{1,0,514} 0,
    20:{2,0,5} 0,   21:{0,0,6} 1,   22:{1,0,4} 0,   23:{2,1,12} 1,  24:{0,0,20} 1,
    25:{1,0,36} 0,  26:{2,0,68} 0,  27:{0,0,132} 1, 28:{1,0,260} 0, 29:{2,0,516} 0,
    30:{0,1,9} 0,   31:{1,1,10} 1,  32:{2,1,12} 1,  33:{0,1,8} 0,   34:{1,1,24} 1,
    35:{2,1,40} 1,  36:{0,1,72} 0,  37:{1,1,136} 1, 38:{2,1,264} 1, 39:{0,1,520} 0,
    40:{1,0,17} 0,  41:{2,0,18} 0,  42:{0,0,20} 1,  43:{1,1,24} 1,  44:{2,0,16} 0,
    45:{0,0,48} 1,  46:{1,0,80} 0,  47:{2,0,144} 0, 48:{0,0,272} 1, 49:{1,0,528} 0,
    50:{2,0,33} 0,  51:{0,0,34} 1,  52:{1,0,36} 0,  53:{2,1,40} 1,  54:{0,0,48} 1,
    55:{1,0,32} 0,  56:{2,0,96} 0,  57:{0,0,160} 1, 58:{1,0,288} 0, 59:{2,0,544} 0,
    60:{0,0,65} 1,  61:{1,0,66} 0,  62:{2,0,68} 0,  63:{0,1,72} 0,  64:{1,0,80} 0,
    65:{2,0,96} 0,  66:{0,0,64} 1,  67:{1,0,192} 0, 68:{2,0,320} 0, 69:{0,0,576} 1,
    70:{1,0,129} 0, 71:{2,0,130} 0, 72:{0,0,132} 1, 73:{1,1,136} 1, 74:{2,0,144} 0,
    75:{0,0,160} 1, 76:{1,0,192} 0, 77:{2,0,128} 0, 78:{0,0,384} 1, 79:{1,0,640} 0,
    80:{2,0,257} 0, 81:{0,0,258} 1, 82:{1,0,260} 0, 83:{2,1,264} 1, 84:{0,0,272} 1,
    85:{1,0,288} 0, 86:{2,0,320} 0, 87:{0,0,384} 1, 88:{1,0,256} 0, 89:{2,0,768} 0,
    90:{0,0,513} 1, 91:{1,0,514} 0, 92:{2,0,516} 0, 93:{0,1,520} 0, 94:{1,0,528} 0,
    95:{2,0,544} 0, 96:{0,0,576} 1, 97:{1,0,640} 0, 98:{2,0,768} 0, 99:{0,0,512} 1,
    100:{1,0,3} 0,
*/
template<size_t NUM_STATE,
        typename OUTPUT_TYPE,
        array<int, NUM_STATE> (*e)(),
        array<int, NUM_STATE> (*next_state)(array<int, NUM_STATE>, int plz, int nlz, int d), 
        OUTPUT_TYPE (*cal_state)(array<int, NUM_STATE>),
        int maxdigit = 9>
class Digit_DP{
  using STATE_TYPE = array<int, NUM_STATE>;
  const static int SZ = 13000000;
  const static int dbgSZ = 300;
  STATE_TYPE dims;
  STATE_TYPE offset;
  bool seen[SZ];
  OUTPUT_TYPE dp[SZ];
  vector<int> dbg_inds;
  STATE_TYPE tmpT[dbgSZ];
  int string_len;
  set<int> used_index;
  int to_index(STATE_TYPE& g, int tight, int lz, int ind){
    int index = 0;
    for(int i=0;i<NUM_STATE;i++) index += offset[i] * g[i];
    index += string_len * 2 * tight + string_len * lz + ind;
    used_index.insert(index);
    return index;
  }
  void clear(){
    for(auto ind:used_index) seen[ind] = 0; used_index.clear();
  }
public:
  Digit_DP(STATE_TYPE EACH_STATE_MAX_DIM, int NUM_LENGTH) : dims(EACH_STATE_MAX_DIM), string_len(NUM_LENGTH) {
    offset[NUM_STATE-1] = NUM_LENGTH * 4;
    for(int i=dims.size()-1;i>0;i--) offset[i-1] = offset[i] * dims[i];
  }
  OUTPUT_TYPE run(string& s, STATE_TYPE state = e(), int tight = 1, int lz = 1, int ind = 0, int dbg_ind=-1, int entry = 1){
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