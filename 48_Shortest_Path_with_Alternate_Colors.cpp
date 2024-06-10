// question -> https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        /*

        Note: Here, edges are coloured and not nodes

            Logic :
                    - Shortest path - use BFS
                    - alternate colors - BFS with constraints
            Algorithm:
                    - maintain 2 adjdenct lists for different colors
                    - start bfs and only push in queue if Alternate color condition 
                      is satisfied
            Extra info:
                    - no need to use min() for red and blue because in BFS, the 
                      first  encounter will be with the smallest path
        */

        vector<int>red[n];
        vector<int>blue[n];

        for(auto it : redEdges){
            int u = it[0];
            int v = it[1];

            red[u].push_back(v);
        }

        for(auto it : blueEdges){
            int u = it[0];
            int v = it[1];

            blue[u].push_back(v);
        }

        // to avoid self loops use visited arrays
        // not only based on node but also color
        set<pair<int,string>> vis; // {node, color}

        // vector to store ans
        vector<int> ans(n,-1);

        // queue to implemnt bfs
        queue<tuple<int,int,string>>q;//{node, lenght, color}
        
        q.push({0,0,"None"});
        vis.insert({0,"None"});
        
        while(!q.empty()){

            auto [node,len,color] = q.front();
            q.pop();

            //condition to check shortest path
            if(ans[node]==-1)ans[node]=len;

            if(color!="Red"){
                for(auto it : red[node]){
                    if(vis.count({it,"Red"})==0){
                        q.push({it,len+1,"Red"});
                        vis.insert({it,"Red"});
                    }
                }
            }

            if(color!="Blue"){
                for(auto it : blue[node]){
                    if(vis.count({it,"Blue"})==0){
                        q.push({it,len+1,"Blue"});
                        vis.insert({it,"Blue"});
                    }
                }
            }
        }
        
        return ans;

    }
};