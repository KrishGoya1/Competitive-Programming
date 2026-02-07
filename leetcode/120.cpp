
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int n;

    int rec(vector<vector<int>>& t, int i, int j){
        if(i >= n) return 0;
        if(i == n-1){
            return dp[i][j] = t[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = t[i][j] + min(
        rec(t,i+1,j),
        rec(t,i+1,j+1)
        );

    }
public:
    int minimumTotal(vector<vector<int>>& t) {
        n = t.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return rec(t,0,0);
        
    }
};



class Solution {
    vector<vector<int>> dp;
    int n;

    int rec(vector<vector<int>>& t, int i, int j){
        if(i >= n) return 0;
        if(i == n-1){
            return dp[i][j] = t[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = t[i][j] + min(
        rec(t,i+1,j),
        rec(t,i+1,j+1)
        );

    }
public:
    int minimumTotal(vector<vector<int>>& t) {
        n = t.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return rec(t,0,0);
        
    }
};

