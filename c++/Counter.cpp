template<typename T> class Counter: unordered_map<T, int>{
	Counter(vector<T> t){
		trav(c, t){
			this[c] += 1;
		}
	}
	vector<int> values(){
		vector<int> t;
		trav(c, this){
			t.pb(c);
		}
		return t;
	}
	vector<T> keys(){
		vector<T> t;
		trav(c, this){
			t.pb(c);
		}
		return t;
	}
}