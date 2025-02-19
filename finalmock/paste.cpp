
    if(inverse==0){
        for(int i = 0; i<n; i++){
            B[i] = 0;
            CC pi;
            for(int j = 0; j<n; j++){
                B[i]+=A[j]*Cexp<CC>(-2*pi*j*Csqrt<CC>(-1)*i/n);
            }
            B[i] /= Csqrt<CC>(n);
        }
    }else{
        for(int i = 0; i<n; i++){
            B[i] = 0;
            CC pi;
            for(int j = 0; j<n; j++){
                B[i]+=A[j]*Cexp<CC>(2*pi*j*Csqrt<CC>(-1)*i/n);
            }
            B[i] /= Csqrt<CC>(n);
        }
    }
