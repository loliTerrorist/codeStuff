#include <bits/stdc++.h>
using namespace std;

template<typename t>
class Poly;
template<typename t1>
class row{
    public:
        vector<t1> entries;
        row(){entries.resize(2);}
        t1& operator[](int index){
            return entries[index];
        }
};

template<typename t1>
class Matrix{
    public:
        vector<row<t1> > entries;
        Matrix(){
            entries.resize(2);
        }
        //Functions
        row<t1>& operator[](int index){
            return entries[index];
        }
        t1 trace(){
            t1 sum = entries[0][0]+entries[1][1];
            return sum;
        }
        t1 det(){
            return entries[0][0]*entries[1][1]-entries[0][1]*entries[1][0];
        }
        //a0, a1, a2
        Poly<t1> char_poly(){
            Poly<t1> ret;
            ret[0] = this->det();
            ret[1] = this->trace()*(-1);
            ret[2] = 1;
            return ret;
        }
};
template<typename t>
class Poly{
    //a0, a1, a2
    public:
    vector<t> coeff;
    Poly(vector<t> cf){
        coeff = cf;
    }
    Poly(){coeff.resize(3);}

    t& operator[] (t i){
        return coeff[i];
    }
    t operator() (t x){
        t sum = coeff[0] + coeff[1]*x + coeff[2]*x*x;
        return sum;
    }
    Matrix<t> operator() (Matrix<t> x){
        Matrix<t> sum = coeff[0] + coeff[1]*x + coeff[2]*x*x;
        return sum;
    }
};
template<typename t1>
Matrix<t1> operator+(Matrix<t1> A, Matrix<t1> B){
    Matrix<t1> retm;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            retm[i][j] = A[i][j]+B[i][j];
        }
    }
    return retm;
}
template<typename t1>
Matrix<t1> operator+(t1 A, Matrix<t1> B){
    Matrix<t1> retm;
    retm[0][0] = A; retm[1][1] = A;
    return retm+B;
}
template<typename t1>
Matrix<t1> operator+(Matrix<t1> A, t1 B){
    return B+A;
}
template<typename t1>
Matrix<t1> operator*(Matrix<t1> A, Matrix<t1> B){
    Matrix<t1> retm;
    retm[0][0] = A[0][0]*B[0][0]+A[0][1]*B[1][0];
    retm[0][1] = A[0][0]*B[0][1]+A[0][1]*B[1][1];
    retm[1][0] = A[1][0]*B[0][0]+A[1][1]*B[1][0];
    retm[1][1] = A[1][0]*B[0][1]+A[1][1]*B[1][1];
    return retm;
}
template<typename t1>
Matrix<t1> operator*(t1 c, Matrix<t1> A){
    Matrix<t1> retm;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            retm[i][j] = c*A[i][j];
        }
    }
    return retm;
}
template<typename t1>
Matrix<t1> operator*(Matrix<t1> A, t1 c){
    return c*A;

}
template<typename t1>
ostream& operator<<(ostream &outt, Matrix<t1> A){
    outt<<A[0][0]<<" "<<A[0][1]<<'\n'<<A[1][0]<<" "<<A[1][1]<<'\n';
    return outt;
}
template<typename t1>
ostream& operator<<(ostream  &outt, Poly<t1> pp){
    outt<<pp[0]<<"+"<<pp[1]<<"x+"<<pp[2]<<"x^2"<<endl;
    return outt;
}

int main() {
//    srand(time(NULL));
    srand(time(NULL));
    Matrix<int> A;
    A[0][0] = rand() % 100;
    A[0][1] = rand() % 100;
    A[1][0] = rand() % 100;
    A[1][1] = rand() % 100;
    cout << "Matrix A is" << endl;
    cout << A << endl;
    Poly<int> poly = A.char_poly();
    cout << "The characteristic polynomial of A is" << endl;
    cout << poly << endl;
    cout << "P(-1) = " << poly(-1) << endl;
    cout << "P(0) = " << poly(0) << endl;
    cout << "P(1) = " << poly(1) << endl;
    cout << "P(A) is " << endl;
    cout << poly(A) << endl;
}
