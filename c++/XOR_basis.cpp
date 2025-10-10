struct XOR_BASIS {
    using num = int;
    static const int dim = 31;
    vector<num> basis;
    int sz;

    XOR_BASIS(){init();}

    void init() {
        basis.resize(dim);
        for(int i = 0; i < dim; i++) basis[i] = 0;
        sz = 0;
    }

    bool insertVector(int mask) {
        for (int i=dim-1;i>=0; i--) {
            if (((mask>>i)&1) == 0) continue;
 
            if (!basis[i]) {
                for(int j=i-1;j>=0;j--) if(basis[j] && (mask >> j & 1)) mask ^= basis[j]; // erase down
                for(int j=i+1;j<dim;j++) if(basis[j] >> i & 1) basis[j] ^= mask; // erase up
                basis[i] = mask;
                ++sz;
                return true;
            }
            mask ^= basis[i];
        }
        return false;
    }
 
    void mergeBasis(const XOR_BASIS &from) {for(int i = dim-1; i >= 0; i--) if(from.basis[i]) insertVector(from.basis[i]);}
 
    num kth(int k){ // kth smallest, 1-base, kth(1) = 0
        k--;
        num ret = 0;
        if(k < 0 || k >= (1 << sz)) return -1;
        for(int i=dim-1, j=sz-1;i>=0;i--){
            if(basis[i]) {
                if(k >> j & 1) ret ^= basis[i];
                j--;
            }
        }
        return ret;
    }
    int rkth(num n){ // n is kth, return 1-base k, 0 -> 1
        int k = 1;
        for(int i=dim-1, j=sz-1;i>=0;i--){
            if(basis[i]) {
                if((n >> i & 1)) n ^= basis[i], k += (1 << j);
                j--;
            }
        }
        if(n != 0) return -1;
        return k;
    }
    int findMax()  {
        return kth(1 << sz);
    }
};