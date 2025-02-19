#include <bits/stdc++.h>
using namespace std;


pair<double,double> LinearRegression(int n, double *X, double *Y){
    double a = 0; double b = 0;
    auto R = [&](double aa, double bb){
        double ret = 0;
        for(int j = 0; j<n; j++){
            double temp = abs(aa*X[j]+bb-Y[j]);
            temp = sqrt(temp);
            temp = pow(temp, 3);
            ret+=temp;
        }
        return ret;
    };
    for(int i = 1; i<=10000; i++){
        double aup = a+1/sqrt(i);
        double adown = a-1/sqrt(i);
        if(R(aup,b)<R(adown,b)){
            a = aup;
        }else{

            a = adown;
        }
        double bup = b+1/sqrt(i);
        double bdown = b-1/sqrt(i);
        if(R(a,bup)<R(a,bdown)){
            b = bup;
        }else{

            b = bdown;
        }
    }
    return make_pair(a, b);
}
/*
pair<double,double> Guess(int n, double *X, double *Y){
    double a = 0; double b = 0;
    auto R = [&](double aa, double bb){
        double ret = 0;
        for(int j = 0; j<n; j++){
            double temp = abs(aa*X[j]+bb-Y[j]);
            temp = sqrt(temp);
            temp = pow(temp, 3);
            ret+=temp;
        }
        return ret;
    };
    for(int i = 1; i<=10000; i++){
        double aup = a+1/sqrt(i);
        double adown = a-1/sqrt(i);
        if(R(aup,b)<R(adown,b)){
            a = aup;
        }else{

            a = adown;
        }
        double bup = b+1/sqrt(i);
        double bdown = b-1/sqrt(i);
        if(R(a,bup)<R(a,bdown)){
            b = bup;
        }else{

            b = bdown;
        }
    }
    return make_pair(a, b);
}*/
double MeanSquaredError(double a, double b, int n, double* X, double* Y) {
    double error = 0.0;
    double pi = M_PI;
    for (int i = 0; i < n; i++) {
        double predicted = sin(2 * pi * (a * X[i] + b));
        error += pow(predicted - Y[i], 2);
    }
    return error / n;
}

pair<double, double> Guess(int n, double* X, double* Y) {
    double best_a = 0, best_b = 0;
    double min_error = 1e9;
    double pi = M_PI;

    double learning_rate = 0.0001;
    int max_iters = 100000;

    double a = rand() / double(RAND_MAX);
    double b = rand() / double(RAND_MAX);

    for (int iter = 0; iter < max_iters; iter++) {
        double error = MeanSquaredError(a, b, n, X, Y);
        if (error < min_error) {
            min_error = error;
            best_a = a;
            best_b = b;
        }

        double grad_a = 0.0, grad_b = 0.0;
        for (int i = 0; i < n; i++) {
            double predicted = sin(2 * pi * (a * X[i] + b));
            double diff = predicted - Y[i];
            grad_a += 2 * diff * cos(2 * pi * (a * X[i] + b)) * 2 * pi * X[i];
            grad_b += 2 * diff * cos(2 * pi * (a * X[i] + b)) * 2 * pi;
        }
        grad_a /= n;
        grad_b /= n;

        a -= learning_rate * grad_a;
        b -= learning_rate * grad_b;
    }
    return {best_a, best_b};
}
int main(){
    srand(time(NULL));
    double pi = M_PI;
    int n = 100;
    double a = rand() / double(RAND_MAX);
    double b = rand() / double(RAND_MAX);
    a = 10 + a * 10;
    b = 0.9 * a * b;
    double X[n], Y[n];
    for (int i = 0; i < n; i++) {
        X[i] = 10 * i / n;
        Y[i] = sin(2 * pi * (a * X[i] + b));
    }
    auto guess = Guess(n, X, Y);
    cout << "true a - guess a is " << guess.first<<endl;
    cout << "true b - guess b is " << guess.second<<endl;
    return 0;
}
