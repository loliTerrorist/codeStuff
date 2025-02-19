#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
CosineTransform(int n, double* A, double* B){
    for(int k = 0; k<n; i++){
        B[k] = 0;
        for(int j = 0; j<n; j++){
            B[k]+=A[j]*cos(j*k*M_PI);
        }
    }
}
template<typename CC>
void FourierTransform(int n, CC* A, CC* B){
    const CC sqrtn = sqrt(n);
    for(int k = 0; k<n; k++){
        B[k] = 0;
        for(int j = 0; j<n; j++){
            B[k]+= (A[j]*exp(-2*PI*II*j*k/n))
        }
        B[k] = B[k] / sqrtn;
    }
}
template<typename CC>
void FourierTransform2D(int m, int n, CC** A, CC**B){
    for(int u = 0; u<n; u++){
        for(int v = 0; v<n; v++){
            const CC sqrtmn = sqrt(m*n);
            for(int x = 0; x<m; x++){
                for(int y = 0; y<n; y++){
                    B[u][v]+=A[x][y]exp(-2*PI*II*(u*x/m+v*y/n));
                }
            }
            B[u][v] /= sqrtmn;
        }
    }
}
template<typename CC>
void FFT(int n, CC* A, CC* B){
     
}
signed main(){
    
}
