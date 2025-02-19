#include <bits/stdc++.h>
using namespace std;

signed main(){
    vector<int> elevation = {4,2,0,3,2,5};
    int n = elevation.size();
    int m = 0;
    for(int i = 0; i<n; i++){
        m = max(m, elevation[i]);
    }
    int trapped_water = 0;
    auto trapwater = [&](){
        //skip the head and the end
        //for each index between, we find the tallest elevation closest to the sides.
        //then take the min of them and subtract it with the index's elevation
        vector<int> maxl(n); vector<int> maxr(n);
        maxl[0] = elevation[0];
        maxr[n-1] = elevation[n-1];
        for(int i = 1; i<n; i++){
            maxl[i] = max(maxl[i-1], elevation[i]);
        }
        for(int i = n-2; i>=0; i--){
            maxr[i] = max(maxr[i+1], elevation[i]);
        }
        vector<int> minmax(n);
        for(int i = 0; i<n; i++){
            minmax[i] = min(maxl[i], maxr[i]);
        }
        for(int i = 1; i<n-1; i++){
            trapped_water += max(0, minmax[i]-elevation[i]);
        }
    };
    trapwater();
    cout<<trapped_water<<endl;
    
}
