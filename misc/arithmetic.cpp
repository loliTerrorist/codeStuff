#include <bits/stdc++.h> 
using namespace std; 
signed main(){
    string exinput; cin>>exinput;
    //TODO: inplement add, sub, mult, quo, power;
    auto add = [&](int a, int b){
        int res = 0; res = a+b;
        res %= 7;
        return res;
    };
    auto sub= [&](int a, int b){
        int res = 0; res = a-b;
        while(res<0) res+=7;
        res %= 7;
        return res;
    };
    auto mult= [&](int a, int b){
        int res = a*b;
        res%=7;
        return res;
    };
    auto quo = [&](int a, int b){
        int res = 0;
        for(int i = 0; i<7; i++){
            if((a+7*i)%b==0) {
                res = (a+7*i) / b;
            }
        }
        return add(res, 0);
    };
    
    
    //TODO: inplement a function that:
    //1. Scan the expression from left to right, pick the operator with the highest priority and evaluate it: if it's an operator, evaluate it and replace its place with the result; if it's a left parenthesis, replace with space and call the function at the next index, if it's a right parenthesis, return and replace with space;
    //2. print the corrosponding modification: Print the modified string, if the operation isn't parenthesis, place \ and / at the corresponding number that is operated on, and add _ in between;
    //3. the function should take in where to start operating; 
    function<void(int)> eval= [&](int start){
        
    };
    cout<<quo(4, 2)<<endl;
}
