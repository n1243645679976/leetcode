#include<vector>
#include<set>
#include<cstdio>
using std::vector;
using std::set;
using std::swap;

template<typename T>
void comb(vector<T>& tar, vector<T>& now, vector<vector<T>>& res, vector<bool>& been, int k, int ind){
	if(k == 0){
		res.push_back(now);
		return;
	}
	if(tar.size() - ind < k) return;
	comb(tar, now, res, been, k, ind+1);
	if(!been[ind]){
		now.push_back(tar[ind]);
		been[ind] = true;
		comb(tar, now, res, been, k-1, ind+1);
		now.pop_back();
		been[ind] = false;
	}
	return;
}
	
template<typename T>
vector<vector<T>> combinations(vector<T>& arr, int k){
	if(k > arr.size() || k <= 0) return {};
	vector<vector<T>> res;
	vector<T> now;
	vector<bool> been(arr.size());
	comb(arr, now, res, been, k, 0);
	return res;
}

template<typename T>
vector<vector<T>> combinations(set<T>& _set, int k){
    vector<T> arr(_set.begin(), _set.end());
	return combinations(arr, k);
}
// n^n
template<typename T>
void perm(vector<T>& tar, vector<T>& now, vector<vector<T>>& res, vector<bool>& been, int k, int ind){
	if(k == 0){
		res.push_back(now);
		return;
	}
    if(ind == tar.size()) return;
	perm(tar, now, res, been, k, ind+1);
	if(!been[ind]){
		now.push_back(tar[ind]);
		been[ind] = true;
		perm(tar, now, res, been, k-1, 0);
		now.pop_back();
		been[ind] = false;
	}
	return;
}

template<typename T>
void permutation(vector<T>& arr, int k) 
{
    for(int j = 1; j < arr.size(); ++j) 
    {
        swap(arr[k % (j + 1)], arr[j]); 
        k = k / (j + 1);
    }
}
template<typename T>
vector<vector<T>> permutations(vector<T>& arr, int k){
	if(k > arr.size() || k <= 0) return {};
	vector<vector<T>> res;
	vector<T> now;
	vector<bool> been(arr.size());
	perm(arr, now, res, been, k, 0);
	return res;
}
template<typename T>
vector<vector<T>> permutations(set<T>& _set, int k){
    vector<T> arr(_set.begin(), _set.end());
	return permutations(arr, k);
}
#ifdef testing
int main(){
    set<char> c{49, 97, 33, 65, 100};
    auto r = combinations(c, 3);
    r = permutations(c, 3);
    for(auto c:r){
        for(auto cc: c){
            printf("%c ", cc);
        }
        printf("\n");
    }
    return 0;
}
#endif