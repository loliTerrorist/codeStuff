#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    vector<vector<double> > tileswlv(50, vector<double>(50, 0));
    string prnt = " .:-=+*#%@";
    auto rain = [&](){
        for(int i = 0; i<50; i++){
            for(int j = 0; j<50; j++){
                tileswlv[i][j] += 10;
            } 
        }
    };

    vector<vector<double> > tilescopy = tileswlv;
    auto drain = [&](){
        for(int i = 0; i<50; i++){
            for(int j = 0; j<50; j++){
                tileswlv[i][j]-=1;
            }
        }
    };

    auto update = [&](int x, int y){
        for(int i = 0; i<4; i++) {
            int neix = x+dx[i];
            int neiy = y+dy[i];
            if(neix<0||neix>=50||neiy<0||neiy>=50){
                
                tilescopy[x][y]-=0.25*tileswlv[x][y];
            }
            else{
                tilescopy[x][y] -=0.25*max(tileswlv[x][y]-tileswlv[neix][neiy], (double)0);
                tilescopy[neix][neiy] += 0.25*max(tileswlv[x][y]-tileswlv[neix][neiy], (double)0);
            }
        }
    };
    
    auto flood = [&]{
        tilescopy = tileswlv;
        for(int i = 0; i<50; i++){
            for(int j = 0; j<50; j++){
                update(i,j);
            }
        }
        tileswlv = tilescopy;
    };  

    auto check = [&]{
        for(int i = 0; i<50; i++){
             for(int j = 0; j<50; j++){
                    if(tileswlv[i][j]>=1) return 0;
             }
        }
        return 1;
    };
    auto getchar = [&](double x){
        int c = floor(x);
        if(c<0) c = 0;
        if(c>9) c = 9;
        return prnt[c];
    };

    auto printtiles = [&](){
        for(int i = 0; i<50; i++){
            for(int j = 0; j<50; j++){
                if(tileswlv[i][j]>=1) cout<<getchar(tileswlv[i][j])<<" ";
                else  cout<<"  ";
            }cout<<endl;
        }cout<<endl;
    };
    int hr = 0;
    for(int i = 0; i<3; i++){
        hr++;
        rain();
        flood();
        drain();
        printtiles();
        if(check()){
            break;
        }
    }
    while(!check()){
        hr++;
        flood();
        drain();
        printtiles();
    }
    
    cout<<hr<<endl;

}
