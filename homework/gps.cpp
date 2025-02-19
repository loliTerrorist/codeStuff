#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>
#include <queue>
#include <vector>
using namespace std;
const double signal_speed = 3000;

// 3-dimensional coordinate
class Coor3d {
    public:
    double x, y, z;
    Coor3d(){}
    Coor3d(double xx, double yy, double zz){
        x = xx;
        y = yy;
        z = zz;
    }
};
// Holds time in addition to coords
// 4-dimensional coordinate
class Coor4d : public Coor3d {
    public:
    double x, y, z;
    std::chrono::time_point<std::chrono::high_resolution_clock> t;
    Coor4d(Coor3d point){
        x = point.x;
        y = point.y;
        z = point.z;
        t = std::chrono::high_resolution_clock::now();
    }
    Coor4d(){}
    Coor4d(double xx, double yy, double zz, double tt){
    
    }
};

// How to cout time
ostream& operator<<(ostream& seaotter, const std::chrono::high_resolution_clock::time_point& time_2b_printed) {
    static auto first_call_time = std::chrono::high_resolution_clock::now();
    auto since_start = time_2b_printed - first_call_time;
    long long since_start_mus = std::chrono::duration_cast<std::chrono::microseconds>(since_start).count();
    seaotter << since_start_mus / 1000. << " ms";
    return seaotter;
}

// How to cout 3d coordinate
ostream& operator<<(ostream& seaotter, const Coor3d& xyz) {
    seaotter<<"x: "<<xyz.x<<" y: "<<xyz.y<<" z: "<<xyz.z<<'\n';
    return seaotter;
}
// How to cout 4d coordinate
ostream& operator<<(ostream& seaotter, const Coor4d& xyzt) {
    seaotter<<"x: "<<xyzt.x<<" y: "<<xyzt.y<<" z: "<<xyzt.z<<" time: "<<xyzt.t<<'\n';
    return seaotter;
}

// The distance between P and Q
double ED(Coor3d P, Coor3d Q) {
    double dx = P.x-Q.x;
    double dy = P.y-Q.y;
    double dz = P.z-Q.z;
    double distance =  sqrt(dx*dx+dy*dy+dz*dz);
    return distance;
}

double ED(Coor3d P, Coor4d Q){
    double dx = P.x-Q.x;
    double dy = P.y-Q.y;
    double dz = P.z-Q.z;
    double distance =  sqrt(dx*dx+dy*dy+dz*dz);
    return distance;
}
double ED(Coor4d P, Coor3d Q){
    return ED(Q, P);
}
double ED(Coor4d P, Coor4d Q){
    double dx = P.x-Q.x;
    double dy = P.y-Q.y;
    double dz = P.z-Q.z;
    double distance =  sqrt(dx*dx+dy*dy+dz*dz);
    return distance;
}

// Random number infrastructure
std::random_device HardwareNoise;
std::mt19937 Engine(HardwareNoise());
std::normal_distribution<double> dist(-1.0, 1.0);
// Sample points at radius r km
Coor3d UniSphere(double r) {
    Coor3d random_point;
    random_point.x = dist(Engine);
    random_point.y = dist(Engine);
    random_point.z = dist(Engine);
    Coor3d origin(0,0,0);
    double rr = ED(random_point, origin);
    random_point.x *= r / rr;
    random_point.y *= r / rr;
    random_point.z *= r / rr;
    return random_point;
}

// Multi-threading infrastructure
std::mutex CoutMutex;
std::mutex SatelliteMutex;
std::mutex CellPhoneMutex;
std::queue<Coor4d> SatelliteBroadcast;
std::queue<Coor4d> CellphoneReception;
std::queue<Coor3d> CellphoneEstimate;

void SatelliteFunction() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // Every second, a random satellite pops up at a random location in the sky
        Coor3d newSatellite = UniSphere(6371+20180);
        // The satellite broadcasts its location and timestamp
        SatelliteMutex.lock();
        Coor4d S4 = Coor4d(newSatellite);
        SatelliteBroadcast.push(S4);
        SatelliteMutex.unlock();

        CoutMutex.lock();
        cout << "A satellite broadcasted at " << endl
             << S4 << endl;
        CoutMutex.unlock();
    }
}
// SignalFunction(cellphone_pos, satellite_pos)
void SignalFunction(Coor3d C3, Coor4d S4) {
    // Calculate the distance between satellite and cellphone
    CoutMutex.lock();
    //
    double distance_km = ED(C3, S4);
    int travel_time_mus = distance_km*1000000/signal_speed;
    cout << string(50, ' ') << "This signal is put to sleep for " << endl
         << string(50, ' ') << travel_time_mus / 1000. << " ms to travel " << distance_km << " km." << endl;
    CoutMutex.unlock();

    // Signal is traveling
    // Now sleep to simulate the travel time
    auto expected_arrival_time = S4.t + std::chrono::microseconds(travel_time_mus);
    std::this_thread::sleep_until(expected_arrival_time);

    CellPhoneMutex.lock();
    // The signal arrived
    CellphoneReception.push(S4);
    CellPhoneMutex.unlock();

    // Broadcast that the signal arrived
    CoutMutex.lock();
    cout << string(80, ' ') << "A signal has arrived" << endl;
    CoutMutex.unlock();
}

void CellphoneFunction() {
    Coor3d C3 = {0, 0, 0}; // let's guess the cellphone's position
    int nSignals = 0;
    while (true) {
        // Check if there is any reception every now:w
        // and then
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        CellPhoneMutex.lock();
        auto Cold = C3;
        if (!CellphoneReception.empty()) {
            // Signal is acknowledge by cellphone
            auto S4 = CellphoneReception.front();
            CellphoneReception.pop();
            CellPhoneMutex.unlock();
            // Record when the signal was received
            auto r4 = std::chrono::high_resolution_clock::now();
            nSignals++;
            CoutMutex.lock();
            cout << string(100, ' ') << "The cellphone received the " << nSignals << "th signal" << endl
                 << string(100, ' ') << S4 << endl
                 << string(100, ' ') << "at time " << r4 << endl;
            CoutMutex.unlock();
            
            // Calculate time difference
                auto time_dif = r4 - S4.t;
            // Calculate distance discrepancy
                double st = signal_speed*(std::chrono::duration_cast<std::chrono::microseconds>(time_dif).count()*1e-6);
                cout<<"st: "<<st<<endl;
                auto distance_error = st-ED(C3, S4);
            // Compute the correction vector
                cout<<"distance error:"<<distance_error<<endl;
                cout<<"dx "<<S4.x/(6371+20180)*distance_error/sqrt(nSignals);

                C3.x -= S4.x/(6371+20180)*distance_error/sqrt(nSignals);
                C3.y -= S4.y/(6371+20180)*distance_error/sqrt(nSignals);
                C3.z -= S4.z/(6371+20180)*distance_error/sqrt(nSignals);
            CoutMutex.lock();
            cout << string(150, ' ') << "Updated Cellphone Position:" << endl
                 << string(150, ' ') << C3 << " +- " << ED(C3, Cold) << "km" << endl;
            CoutMutex.unlock();

            // S5 = S4;
//            r5 = r4;
        }
        else {
            CellPhoneMutex.unlock();
        }
    }
}

int main() {
    Coor3d CellphonePosition = UniSphere(6371);
    CoutMutex.lock();
    cout << "Cellphone is fixed at " << endl
         << CellphonePosition << endl;
    CoutMutex.unlock();

    std::thread SatelliteThread(SatelliteFunction);
    std::thread CellphoneThread(CellphoneFunction);

    while (true) {
        // Every microsecond, check if there is any broadcast
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        SatelliteMutex.lock();
        if (!SatelliteBroadcast.empty()) {
            Coor4d S4 = SatelliteBroadcast.front();
            SatelliteBroadcast.pop();
            SatelliteMutex.unlock();
            // One thread per signal
            std::thread SignalThread(SignalFunction, CellphonePosition, S4);
            SignalThread.detach();
        }
        else {
            SatelliteMutex.unlock();
        }
    }

    SatelliteThread.join();
    CellphoneThread.join();
    cout << "All threads join the main thread.  Program ends." << endl;
}
