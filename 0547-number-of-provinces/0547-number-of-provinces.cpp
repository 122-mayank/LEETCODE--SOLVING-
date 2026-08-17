class Solution {
public:
    void dfs(int node,  unordered_map<int ,bool>&visited ,  
    unordered_map<int,list<int>>&mp){

        visited[node] = true;

        for(auto neigh : mp[node]){
             if(visited[neigh] == false){
                 dfs(neigh , visited , mp);
             }
        }
         

    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        //make the map
        unordered_map<int,list<int>>mp;

        for(int i = 0 ; i < isConnected.size() ; i++){
             for(int j = 0 ; j < isConnected[i].size() ; j++){
                   if(isConnected[i][j] == 1){
                       mp[i].push_back(j);
                   }
             }
        }

        unordered_map<int ,bool>visited;
        int count = 0;

        for(auto neigh : mp){
             
             if(visited[neigh.first] == false){
                  dfs(neigh.first , visited , mp);
                  count = count + 1;
             }

        }

        return count;
        
    }
};