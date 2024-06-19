class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        /*
            Observation:
                        - Nodes with '0' outdegree has no prerequisite.

            Algorithm: (BFS Approach)
                        - Calculate outdegree of all nodes
                        - push all nodes with outdegree '0' to queue
                        - mantain an adjacency list with opposite passion :
                                                                            - mp.first = Prerequisite 
                                                                            - mp.second = Course
                        - Start BFS traversal and decrease outdegree of neighbor by '1'
                        - if outdegree is '0' - push in queue
        */

        // vector to store courses that can be completed
        vector<int> ans;

        // opposite fashioned - adjacency list
        vector<int>adj[numCourses];
        // vector to count outdegree
        vector<int>outdegree(numCourses);

        for(auto it : prerequisites){

            int course = it[0];
            int prereq = it[1];

            outdegree[course]++;

            adj[prereq].push_back(course);
        }

        // queue for BFS traversal
        queue<int>q;

        // push all nodes with outdegree '0' into queue
        for(int i = 0;i<numCourses;i++){
            
            if(outdegree[i]==0)q.push(i);
        }

        // start BFS traversal
        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto it : adj[node]){

                outdegree[it]--;

                if(outdegree[it]==0){
                    q.push(it);
                }
            }

            ans.push_back(node);

        }

        if(ans.size()>=numCourses)return true;

        else return false;
    }
};