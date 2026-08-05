class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        //step - 1 make the map
        unordered_map<int , list<int>>adj;
        for(auto edge : invocations){
             int u = edge[0];
             int v = edge[1];
             adj[u].push_back(v);
        }

        vector<int>kGroups;
        unordered_set<int>st;
        //step - 2 do the bfs
        queue<int>q;
        q.push(k);

         unordered_map<int , bool>visited;
         visited[k] = true;
        while(!q.empty()){

            int frontNode = q.front();
            q.pop();

            st.insert(frontNode);

            for(auto neigh : adj[frontNode]){

                if(visited[neigh] == false ){
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }

        bool flag = false;
        for(int i = 0 ; i < n ; i++){

             if(st.find(i) == st.end()){
                
                kGroups.push_back(i);

                for(auto neigh : adj[i]){

                     if(st.find(neigh) != st.end()){
                        flag = true;
                        break;
                     }

                }

            }
        }

        if(flag){
            for(auto val : st){
                kGroups.push_back(val);
            }
        }

        return kGroups;

    }
};