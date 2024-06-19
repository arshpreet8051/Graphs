// DFS approach with cycle detection

class Solution {
public:
    bool dfs_cycle_detection(int node,vector<int>adj[],vector<bool>&vis,vector<bool>&current_vis){

        vis[node] = current_vis[node] = true;

        for(auto it : adj[node]){

            if(vis[it]==false){
                if(dfs_cycle_detection(it,adj,vis,current_vis))return true;
            }
            else if(vis[it]==true and current_vis[it]==true)return true;
        }

            current_vis[node] = false;

            return false;

    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<bool> vis(n,false), current_vis(n,false);

        vector<int> adj[n];

        for(auto it : prerequisites){

            int course = it[0];
            int prereq = it[1];

            adj[course].push_back(prereq);
    
        }

        for(int i = 0;i<n;i++){
            if(vis[i]==false){
                if(dfs_cycle_detection(i,adj,vis,current_vis))return false;
            }
        }

        return true;
    }
};