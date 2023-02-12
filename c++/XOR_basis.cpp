const int d = 31;
struct XOR_BASIS {
    int basis[d] = {0};
    int sz;
 
    void init() {
        for(int i = 0; i < d; i++) basis[i] = 0;
        sz = 0;
    }
 
    void insertVector(int mask) {
        for (int i = d-1; i >= 0; i--) {
            if (((mask>>i)&1) == 0) continue;
 
            if (!basis[i]) {
                basis[i] = mask;
                ++sz;
                return;
            }
            mask ^= basis[i];
        }
    }
 
    void mergeBasis(const XOR_BASIS &from) {
        for(int i = d-1; i >= 0; i--) {
            if(!from.basis[i])
                continue;
 
            insertVector(from.basis[i]);
        }
    }
 
    int findMax()  {
        int ret = 0;
        for(int i = d-1; i >= 0; i--) {
            if(!basis[i] || (ret>>i & 1))
                continue;
 
            ret ^= basis[i];
        }
        return ret;
    }
};
#ifdef testing
#include<iostream>
using namespace std;
void answer(){
    XOR_BASIS mbase;
    int N, c;
    cin>>N;
    for(int i=0;i<N;i++){
        cin >> c;
        mbase.insertVector(c);
    }
    cout<<mbase.findMax()<<endl;
}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        answer();
    }
}
#endif