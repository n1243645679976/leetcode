class SPLIT{
public:
    string m_deli, m_target;
	int preind = 0, m_ls;
    SPLIT(string target, string deli){
        m_target = target;
		m_deli = deli;
        m_ls = target.size();
    }
    vector<string> split_all(){
        vector<string> vs;
        while(!end()){
            vs.push_back(next_string());
        }
        return vs;
    }
    string next_string(){
        if(end()) return "";
		int nextind = m_target.find(m_deli, preind);
        int temp = preind;
        preind = nextind + 1;
        if(preind == 0) preind = m_ls;
        return m_target.substr(temp, nextind - temp);
    }
	pii next_interval(){
        if(end()) return {-1, -1};
		int nextind = m_target.find(m_deli, preind);
        int temp = preind;
        preind = nextind + 1;
        if(preind == 0) preind = m_ls;
        return {temp, nextind};
	}
    bool end(){
        return preind == m_ls;
    }
};