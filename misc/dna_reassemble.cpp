#include <bits/stdc++.h>
#define pb push_back
using namespace std;

signed main(){
    freopen("frag1.txt", "r", stdin);
    vector<string> sequences;
    unordered_map<string, string> nextc;
    string input;
    while(cin>>input){
        sequences.pb(input);
        for(int i = 0; i<90; i++){
            nextc[input.substr(i, 10)] = input[i+10];
        }
    }
    string recon_post;
     
}
