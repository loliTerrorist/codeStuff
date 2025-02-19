#include <bits/stdc++.h>
using namespace std;

signed main(){
    freopen("Image.txt", "w", stdout);
    cout<<'{'<<endl;
    for(int i = 0; i<100; i++){
        cout<<'{'<<endl;

        for(int j = 0; j<99; j++){
        cout<<j%10<<", ";
        }
        cout<<100%10<<"},";
        cout<<endl;

    }
    cout<<'}'<<endl;
    fclose(stdout);
}
