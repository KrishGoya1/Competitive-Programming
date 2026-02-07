#include <iostream>
#include <vector>
#include <string>

using namespace std;

string func(string word){
    int n = word.size();
    if(n <= 10) return word;
    string ans = "";
    ans += word[0];

    ans += to_string(n - 2);
    
    ans += word[n-1];

    return ans;
}

int main(){

    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0 ; i < n ; ++i){
        int v1,v2,v3;
        cin >> v1;
        cin >> v2;
        cin >> v3;
        
        if(v1 + v2 + v3 >= 2) ++ans;
    }

    cout << ans;

}