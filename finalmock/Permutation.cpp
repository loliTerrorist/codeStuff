#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

class permutation{
    public:
        vector<int> images;
        permutation(){
            images.resize(1);
        }
        permutation(vector<int> input){
            images = input;
        }
        permutation(int n){
            images.resize(n);
        }
        int size(){
            return pmtt.size();
        }
        int pmtt(int i){
            if(i<pmtt.images.size()){
                return images[i];
            }else{
                return i;
            }
        }
        vector<int> reduce(){
            int index = 0;
            for(int i = 0; i<images.size(); i++){
                if(images[i]!=i) index = i;
            }
            vector<int> ret = slice(images, 0, index+1);
            return ret;
        }
};

ostream& operator<<(ostream& otter, const Permutation& pmtt){
    otter<<"Permutation({";
    for(int i = 0; i<pmtt.size(); i++){
        otter<<permutation(i);
        if(i<pmtt.size()-1) cout<<",";
    }
    otter<<"})"<<endl;
    return otter;
}
bool operator==(permutation p1, permutation p2){
    if(p1.reduce()==p2.reduce()) return 1;
    else return 0;
}
permutation operator~(permutation p){
    permutation inverse(p.size());
}
signed main(){

}
