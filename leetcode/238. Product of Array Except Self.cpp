#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        vector<int> ans(nums.size(),1);
        for(int i = 1 ; i < nums.size() ; ++i){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int suf = 1;
        for(int i = nums.size()-1 ; i >= 0 ; --i){
            ans[i] *= suf;
            suf *= nums[i];
        }
        return ans;
    }
};

class TestCases{
    vector<vector<int>> tc;
    vector<vector<int>> sol;
}


void main(){
    Solution s;
    vector<vector<int>> tc;
    vector<int> sol_1 = {0,0,9,0,0};
    tc.push_back({-1,1,0,-3,3});

    
}