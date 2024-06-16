// Link -> https://www.geeksforgeeks.org/problems/clone-graph/1

class Solution {
public:
    Node* cloneGraph(Node* node) {
        /*
        
        Algo:
             - Map old node with new node by allocating it a new address
             - Travers (BFS) old nodes and marks neighbors array for new nodes using map
        */
        
        unordered_map<Node*,Node*>mp;
        unordered_map<Node*,bool>vis;
        queue<Node*> q;
        
        q.push(node);
        vis[node] = true;
        
        while(!q.empty()){
            
            Node* temp = q.front();
            q.pop();
            
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            
            for(auto it : temp->neighbors){
                
                if(vis[it]==false){
                    vis[it] = true;
                    q.push(it);
                }
            }
            
        }
        
        Node* ans = mp[node];
        
        unordered_map<Node*,bool>vis2;
        
        q.push(node);
        vis2[node] = true;
        
        while(!q.empty()){
            
            Node* temp = q.front();
            q.pop();
            
            Node* newNode = mp[temp];
            
            for(auto it : temp->neighbors){
                
                newNode->neighbors.push_back(mp[it]);
                
                if(vis2[it]==false){
                    
                    vis2[it] = true;
                    q.push(it);
                }
                
            }
            
        }
        
        return ans;
    }
};