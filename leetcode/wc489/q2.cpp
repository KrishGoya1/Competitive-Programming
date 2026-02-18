class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(const auto& num : nums){
            if(!mp[num]){
                mp[num] = 1;
            }else mp[num] = mp[num] + 1;
        }

        

        unordered_map<int,int> freq;

        for(const auto& m : mp){
            if(!freq[m.second]){
                freq[m.second] = 1;
            }else{
                freq[m.second]+=1;
            }
        }

        for(const auto& num : nums){
            if(freq[mp[num]] == 1){
                return num;
            }
        }
        return -1;
    }
};