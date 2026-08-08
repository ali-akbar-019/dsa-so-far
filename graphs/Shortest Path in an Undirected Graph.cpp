class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        //dijekstras algo
        unordered_map<int, vector<pair<int,int>>>adj;
        for(auto &edge:edges){
            int u = edge[0];
            int v= edge[1];
            int cst = edge[2];
        
            adj[u].push_back({v, cst});
            adj[v].push_back({u, cst});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result(V + 1, INT_MAX);
        vector<int> parent(V + 1);
        result[src] = 0;
        for(int i =1 ;i <= V; i++){
            parent[i] = i;
        }
        pq.push({0, src});
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
               pq.pop();
            if(d > result[node]) continue;
            
         
            for(auto &ngbr: adj[node]){
                int ngbr_node = ngbr.first;
                int ngbr_d = ngbr.second;
                if(d + ngbr_d < result[ngbr_node]){
                    result[ngbr_node] = d + ngbr_d;
                    pq.push({d + ngbr_d, ngbr_node});
                    parent[ngbr_node] = node;
                }
            }
        }
        if(result[dest] == INT_MAX){ return {-1};}
        int node = dest;
        vector<int> path;
        while(node != parent[node]){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);
        reverse(begin(path), end(path));
        return path;
    }
};