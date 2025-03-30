class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        deque<tuple<int, int, int>> heap;
        unordered_set<int> visited_state;
        int node_count = graph.size();
        int state;
        int tar = (1<<node_count) - 1;
        
        for(int i=0;i<node_count;i++){
            heap.push_back(tuple<int, int, int>(0, i, 1<<i));
        }
        while(!heap.empty()){
            tuple<int, int, int> tiii = heap.front();
            heap.pop_front();
            int step = get<0>(tiii), now = get<1>(tiii), visited = get<2>(tiii);
            
            if(visited == tar){
                return step;
            }
            for(int c: graph[now]){
                state = (1<<(c+13)) + (visited | (1<<c));
                if(visited_state.find(state) == visited_state.end()){
                    visited_state.insert(state);
                    heap.push_back(tuple<int, int, int>(step+1, c, visited | (1<<c)));
                }
            }
        }
        return -1;
    }
};