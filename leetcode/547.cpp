class Solution {
    void dfs(const vector<vector<int>>& isConnected,vector<int>& visited, int curr){
        visited[curr] = 1;
        for(int next = 0; next < isConnected[curr].size() ; ++next){
            if(isConnected[curr][next] && !visited[next]){
                dfs(isConnected,visited,next);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<int> visited(isConnected.size(), 0);

        for(int i = 0 ; i < isConnected.size() ; ++i){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                ++ans;
            }
        }
        return ans;
    }
};