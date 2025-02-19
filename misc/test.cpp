#include <bits/stdc++.h>
using namespace std;



int counter1 = 0;
mutex d;
void IncreaseCounter() {
    for (int i = 0; i < 100000; ++i) {
        d.lock();
        ++counter1;
        d.unlock();
    }
}
int main() {
    std::thread ManyThreads[1000];
    for (int i = 0; i < 1000; ++i) {
        ManyThreads[i] = std::thread(IncreaseCounter);
    }
    for (int i = 0; i < 1000; ++i) {
        ManyThreads[i].join();
    }
    cout << "Should be 100000000 but ... " << counter1 << endl;
}
