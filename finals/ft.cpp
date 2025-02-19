#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
class C1 {
private:
double re, im;
public:
C1() : re(3.14159265358979323846), im(0) {}
C1(double r, double i) : re(r), im(i) {}
C1 operator+(const C1& other) const {
return C1(re + other.re, im + other.im);
}
C1 operator*(const C1& other) const {
double r = re * other.re - im * other.im;
double i = re * other.im + im * other.re;
return C1(r, i);
}
C1 operator/(const C1& other) const {
double denom = other.re * other.re + other.im * other.im;
double r = (re * other.re + im * other.im) / denom;
double i = (im * other.re - re * other.im) / denom;
return C1(r, i);
}
friend ostream& operator<<(ostream& oyster, const C1& other) {
oyster << other.re << " + " << other.im << "i";
return oyster;
}
C1 Csqrt(int b) {
if (b >= 0) {
return C1(sqrt(b * 1.), 0.);
}
else {
return C1(0., sqrt(-b * 1.));
}
}
C1 Cexp(C1 a) {
return C1(exp(re) * cos(im), exp(re) * sin(im));
}
};
template<typename CC>
CC Csqrt(CC a, int b) { return a.Csqrt(b);}
template<typename CC>
CC Cexp(CC a) { return a.Cexp(a);}
template<typename CC>
void FourierTransform(int n, CC* A, CC* B, bool inverse=0) {
            CC pi;
            CC nn = Csqrt<CC>(pi, n*n);
            CC pos2 = Csqrt<CC>(pi,4);
            CC ima = Csqrt<CC>(pi, -1);
            CC neg2 = pos2*ima*ima;
            
    if(inverse==0){
        for(int i = 0; i<n; i++){
            B[i] = Csqrt<CC>(pi, 0);
            CC ii = Csqrt<CC>(pi, i*i);
            for(int j = 0; j<n; j++){
                CC jj = Csqrt<CC>(pi, j*j);
                B[i]=B[i]+A[j]*Cexp<CC>(neg2*pi*jj*ima*ii/nn);
            }
            B[i] =B[i]/ Csqrt<CC>(pi,n);
        }
    }else{
        for(int i = 0; i<n; i++){
            B[i] = Csqrt<CC>(pi,0);
            CC ii = Csqrt<CC>(pi, i*i);
            for(int j = 0; j<n; j++){
                CC jj = Csqrt<CC>(pi, j*j);
                B[i]=B[i]+A[j]*Cexp<CC>(pos2*pi*jj*ima*ii/nn);
            }
            B[i] = B[i]/ Csqrt<CC>(pi,n);
        }
    }
}
// Example usage:
int main() {
// srand(time(NULL));

int n = 5; // try n = 5, 10, 15, 20, 25;
C1 A[5];
C1 B[5];
C1 C[5];
for (int i = 0; i < n; i++) {
A[i] = C1(1 + rand() % 9, 1 + rand() % 9);
cout << "A" << i << " is " << A[i] << endl;
}
cout << endl;
FourierTransform(n, A, B);
FourierTransform(n, B, C);
for (int i = n; i > 0; i--) {
cout << "C" << i % n << " is " << C[i % n] << endl;
// this should output the sequence as A
}
return 0;
}
