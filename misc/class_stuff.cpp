#include <bits/stdc++.h>
using namespace std;

class CC{
    public:
        float r, i;
        CC(float real, float imagine){
            r = real;
            i = imagine;
        }
        CC operator+(CC a){
            CC ret(a.r+r, a.i+i);
            return ret;
        }
        CC operator* (CC a){
            CC ret(a.r*r-a.i*i, a.r*i+a.i*r);
            return ret;
        }
        CC operator- (CC a){
            CC ret(r-a.r, i-a.i);
            return ret;
        }
        CC conjugate(){
            CC ret(r, (-1)*i);
            return ret;
        }
};


ostream operator<< (ostream& cout2, CC z){
    cout2<<z.r<<" + "<<z.i<<"i";
    return cout2;
}



void print(CC c){
    cout<<c.r<<" + "<<c.i<<"i"<<endl;
}

signed main(){
    CC a(1, 1);
    CC b(1, 2);
    CC s = a-b;
    print(s.conjugate());
}


