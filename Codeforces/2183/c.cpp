#include<bits/stdc++.h>
using namespace std;

int ans(int n, int days, int home){
    /*
        if days >= 2n+3 which is more than enough days
            return n
        
        if home is exactly in the center
            if days <=n
                return days
            else
                return n

        
        
        if home is not on the edge
            if days < smaller side 
                return (days + 3) / 2;
                for all n > 1
            else if days >= smaller side
    
    */

}


int main(){
    int t;
    cin >> t;
    vector<int> v(3);
    for(int i = 0 ; i < t ; ++i){
        cin >> v[0] >> v[1] >> v[2];
        int us = ans(v[0],v[1],v[2]);
        cout << us << endl;
    }

    return 0;
}