#include <iostream>
using namespace std;
struct Qubit {
    double p, q, r, s;
};
Qubit initialize() {

}
void apply_measurement(Qubit &Q) {
    // cout << "M " << Q.p << " " << Q.q << " " << Q.r << " " << Q.s << endl;
    double newp = Q.p/(Q.p+Q.q);
    double newq = Q.q/(Q.p+Q.q);
}
void apply_not(Qubit &Q) {
    // cout << "N " << Q.p << " " << Q.q << " " << Q.r << " " << Q.s << endl;
}
void apply_hadamard(Qubit &Q) {
    // cout << "H " << Q.p << " " << Q.q << " " << Q.r << " " << Q.s << endl;
}
void apply_fujisan(Qubit &Q) {
    // cout << "F " << Q.p << " " << Q.q << " " << Q.r << " " << Q.s << endl;
}
void process_operations(Qubit &Q, string &operations) {

}
int main() {
    string TestingCases[12] = {
        "HM", "NM", "FM",
        "HHM", "HNM", "HFM",
        "NHM", "NNM", "NFM",
        "FHM", "FNM", "FFM"
    };
    for (int ndx = 0; ndx < 12; ndx ++) {
        string operations = TestingCases[ndx];
        Qubit Q = initialize();
        process_operations(Q, operations);
        cout << operations << " --> " << Q.p - Q.q << endl;
    }
}
/*
* HM --> 0
* NM --> -1
* FM --> -0.28
* HHM --> 1
* HNM --> 0
* HFM --> 0.96
* NHM --> 0
* NNM --> 1
* NFM --> 0.28
* FHM --> -0.96
* FNM --> 0.28
* FFM --> -0.8432
*/
[95] For these bonus problems,
