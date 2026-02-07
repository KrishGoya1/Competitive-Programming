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
    vector<string> words;
    for(int i = 0 ; i < n ; ++i){
        string word = "";
        cin >> word;
        words.push_back(word);
    }

    for(int i = 0 ; i < n ; ++i){
        cout << func(words[i]) << endl;
    }
}