class disjoint_set{
  
  vector<int>parent,size;
  
  public:
  disjoint_set(int n){
      parent.resize(n+1);
      size.resize(n+1,1);
      
      for(int i = 0;i<=n;i++){
          parent[i] = i;
      }
  }
  
  int find_ultimate_parent(int node){
      
      if(parent[node]==node){
          return node;
      }
      
      return parent[node] = find_ultimate_parent(parent[node]);
  }
  
  void union_by_size(int u,int v){
      
      int ulp_u = find_ultimate_parent(u);
      int ulp_v = find_ultimate_parent(v);
      
      if(ulp_u==ulp_v)return;
      
      if(size[ulp_u] > size[ulp_v]){
          parent[ulp_v] = ulp_u;
          size[ulp_u] += size[ulp_v];
      }
      else{
          parent[ulp_u] = ulp_v;
          size[ulp_v] += size[ulp_u];
      }
  }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        
        int n = accounts.size();
        disjoint_set ds = disjoint_set(n);
        
        // to map emails with respectice account name index
        unordered_map<string,int> mp;
        
        for(int i = 0;i<n;i++){
            // j from 1 coz '0' is account name and we are already using index for names
            for(int j = 1;j<accounts[i].size();j++){
                
                string mail = accounts[i][j];
                
                // if no overlapping
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                
                // if overlapping occurs
                else{
                    // union of current index having same mail as stored earlier in map
                    ds.union_by_size(i,mp[mail]);
                }
            }
        }
        
        vector<string> merged_mails[n];
        
        for(auto it : mp){
            
            string mail = it.first;
            // NOTE : push in ultimate parent's node
            int node = ds.find_ultimate_parent(it.second);
            merged_mails[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i = 0;i<n;i++){
            if(merged_mails[i].size()==0)continue;
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            
            sort(merged_mails[i].begin(),merged_mails[i].end());
            
            for(auto it : merged_mails[i]){
                temp.push_back(it);
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
};