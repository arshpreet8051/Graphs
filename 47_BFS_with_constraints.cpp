// question link -> https://practice.geeksforgeeks.org/contest/gfg-weekly-158-rated-contest/problems

class Solution {
  public:
   bool isInvalid(int a,int b,int c){
       if(b == -1 or c == -1)return false;
       
       return (a % 2 == 1 && b % 2 == 1 && c % 2 == 1 && a > b && b > c);
   }
    int minTime(int n, int m, vector<vector<int>>& edges) {
        
        vector<int> adj[n+1];
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // note: Here they have asked shortest path , so we will use BFS
        
        queue<tuple<int,int,int,int>>q; // {current node, last node, second_last node, time}
        set<tuple<int,int,int>>vis;//to keep track of visited nodes
        
        q.push(make_tuple(1,-1,-1,0));
        
        vis.insert(make_tuple(1,-1,-1));
        
        while(!q.empty()){
            
            auto state = q.front();
            q.pop();
            
            int current = get<0>(state);
            int last = get<1>(state);
            int second_last = get<2>(state);
            int _time = get<3>(state);
            
            if(current == n)return _time;
            
            for(auto it : adj[current]){
                
                if(isInvalid(it,current,last))continue;
                
                auto new_val = make_tuple(it,current,last);
                
                if(vis.count(new_val)==0){
                    q.push(make_tuple(it,current,last,_time+1));
                    vis.insert(new_val);
                }
            }
        }
        return -1;
    }
};