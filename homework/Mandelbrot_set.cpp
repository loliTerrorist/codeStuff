#include <vector>
#include <cmath>
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

class CCC {
    public:
    CCC(){}
    double r, i;
    CCC(double a, double b){
        r = a; i = b;
    }
    double abs(){
        return sqrt(r*r+i*i);
    }
    CCC conjugate(){
        return CCC(r, -i);
    }
};


CCC operator""i(unsigned long long digits) {
    CCC ret(0, (double)digits);
    return ret;
}
CCC operator""i(long double digits) {  
    CCC ret(0, digits);
    return ret;
}
std::ostream& operator<<(std::ostream& seaotter, CCC z) {
    seaotter<<z.r<<" + "<<z.i<<"i";
    return seaotter;
}
CCC operator+(CCC c) { return c; } // unary +
CCC operator+(CCC lhs, double rhs) { 
    CCC ret(lhs.r+rhs, lhs.i);
    return ret;
}
CCC operator+(double lhs, CCC rhs) {
    return rhs+lhs;
}
CCC operator+(CCC lhs, CCC rhs) {
    CCC ret(lhs.r+rhs.r, lhs.i+rhs.i);
    return ret;
}

CCC operator-(CCC c) { 
    CCC ret = c;
    ret.r *= -1;
    ret.i *= -1;
    return c;
} // unary -
CCC operator-(CCC lhs, double rhs) { 
    CCC ret(lhs.r-rhs, lhs.i);
    return ret;
}
CCC operator-(double lhs, CCC rhs) {
    CCC ret(lhs-rhs.r, rhs.i);
    return ret;
}
CCC operator-(CCC lhs, CCC rhs) {
    CCC ret(lhs.r-rhs.r, lhs.i-rhs.i);
    return ret;
}

CCC operator*(CCC lhs, double rhs) {
    CCC ret(lhs.r*rhs, lhs.i*rhs);
    return ret;
}
CCC operator*(double lhs, CCC rhs) {  
    return rhs*lhs;
}
CCC operator*(CCC lhs, CCC rhs) { 
    CCC ret(lhs.r*rhs.r-lhs.i*rhs.i, lhs.r*rhs.i+lhs.i*rhs.r);
    return ret;
}

CCC operator/(CCC lhs, double rhs) {
    CCC ret(lhs.r/rhs, lhs.i/rhs);
    return ret;
}
CCC operator/(double lhs, CCC rhs) { 
    double bottom = rhs.r*rhs.r-rhs.i*rhs.i;
    return CCC(lhs/bottom*rhs.r, -lhs/bottom*rhs.i);
}
CCC operator/(CCC lhs, CCC rhs) { 
    CCC ret = lhs*rhs.conjugate()/(rhs.r*rhs.r-rhs.i*rhs.i);
    return ret;
}
class Cpoly {
    public:
        Cpoly(){
        }
        ~Cpoly(){
        }
        CCC coeff[100];
///        vector<CCC> coeff{vector<CCC>(100)};

};

Cpoly operator+(Cpoly &f, Cpoly &g){
    Cpoly s;
    for(int i = 0; i<100; i++){
        s.coeff[i] = f.coeff[i]+g.coeff[i];
    }
    return s;
}
Cpoly operator-(Cpoly &f, Cpoly &g){
    Cpoly s;
    for(int i = 0; i<100; i++){
        s.coeff[i] = f.coeff[i]-g.coeff[i];
    }
    return s;
}
Cpoly operator*(CCC c, Cpoly &f){
    Cpoly s;
    for(int i = 0; i<100; i++){
        s.coeff[i] = s.coeff[i]*c;
    }
    return s;
}

Cpoly operator*(Cpoly &f, CCC c){
    Cpoly s;
    for(int i = 0; i<100; i++){
        s.coeff[i] = s.coeff[i]*c;
    }
    return s;
}
Cpoly operator/(Cpoly &f, CCC c){
    return f*(1./c);
}
int main() {
    for (double y = -2; y <= 2; y += 0.05) {
        for (double x = -2; x <= 2; x += 0.05) {
            CCC c = x + y * 1i;
            CCC z = 0 + 0i;
            /**Perform the iteration z = z * z + c 1000 times;
            If z.abs() > 0, cout a '#';
            Otherwise, cout a space;**/
            for(int i = 0; i<1000; i++){
                z = z*z + c;
            }
            if(z.abs()>0) cout<<'#';
            else cout<<' ';
        }
        cout << endl;
    }
}

 
