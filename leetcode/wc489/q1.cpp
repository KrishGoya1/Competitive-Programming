class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int> mp;
        for(const auto& b : bulbs){
            if(!mp[b]){
                mp[b] = 1;
            }else{
                mp[b] = 0;
            }
        }
        vector<int> ans;
        for(const auto& m : mp){
            if(m.second == 1){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};