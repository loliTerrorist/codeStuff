#include <bits/stdc++.h>
#define int signed long long
using namespace std;
// vector<int> mdays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void add_interest(int &loan, int interest){
    loan+=loan*interest/1000;
//    a.bcxx+a.bcxx*0.003 ->abc.xx+abc.xx*3/1000->ab(c+d).xx
}
bool simulate_payment(long long L, long long P) {
    // 2030/01/05 to 2040/12/20
    int fl = L;
    int interest=3;
    for(int month = 1; month<=12*11; month++) {
        if(month>6) interest = 2; 
        //aad_interest(fl, interest);
        fl += fl*0.003;
        fl -= P;
        cout << "fl" << fl << endl;
        //        cout<<"loan left: "<<fl<<endl;
    }
    if(fl<=0){
        return true;
    }else{
        return false;
    }
}
int calculate_min_payment(int L) {
    int r, l;
    
    l = 1; r = L;
    cout << "before while";
    while(l<r){
        int mid = (l+r)/2;
        bool res = simulate_payment(L*10, mid*10);
        cout << res << " ";
        if(res){   
            //mid can satisfy
            r = mid;
        }else{
            //mid cannot satisfy, check mid-1
            l = mid+1;
        }
        cout<<"l: "<<l<<" r: "<<r<<endl;
    }
    // cout<<l<<" "<<r<<endl;
    return l;
}
signed main() {
    
    long long TestingCases[5] = {10000000000000000 , 1000, 10000, 100000, 1000000};
    for (int ndx = 0; ndx < 1; ndx ++) {
 //       int L = TestingCases[ndx];
        int L = 1000;
        int P = calculate_min_payment(L);
//        int decimal2 = P/10-10*(P/100);
  //      int decimal1 = P/100-10*(P/1000);
    //    if(decimal2>5) decimal1++;
        cout << "v11" << endl;
        cout << "Loan: " << L << " --> Payment: " << P << "\n";
    }
}
/*
* 1000 --> 9
* 10000 --> 87
* 100000 --> 868
* 1000000 --> 8678
* 10000000 --> 86780
* 100000000 --> 867791
* 1000000000 --> 8677909
* 10000000000 --> 86779082
* 100000000000 --> 867790813
* 1000000000000 --> 8677908125
* 10000000000000 --> 86779081241
* 100000000000000 --> 867790812405
* 1000000000000000 --> 8677908124043
* 10000000000000000 --> 86779081240425
*/
