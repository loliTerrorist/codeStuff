#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

random_device rd;
mt19937 engine(rd());
int DigitZero[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int DigitOne[10][10] = {
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int DigitTwo[10][10] = {
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int DigitThree[10][10] = {
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
};

int DigitFour[10][10] = {

    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int DigitFive[10][10] = {

    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
};

int DigitSix[10][10] = {

    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
};

int DigitSeven[10][10] = {

    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
};

int DigitEight[10][10] = {

    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
};

int DigitNine[10][10] = {

    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
};

int Brain[10][10];
// our brain can dream about 10 x 10 image

float LinkWeights[10][10][10][10];
// LinkWeights[y][x][y2][x2] is high-
// if [y][x] and [y2][x2] should be the same
// low if they should be different

void WatchImage(int Image[10][10]) {
    /*
        Watch the image and adjust the weights  
        Use four layers of loops to iterate through
        coordinates x, y, x2, y2
        Consider the four pixels
        Brain[y][x], Brain[y2][x2], Image[y][x], Image[y2][x2];
        If these two pixel are different in the image
        but our brain think they are,
        decrease the weight LinkWeights[y][x][y2][x2] by 0.001.
        If these two pixel are the same in the image
        but our brain think they are different,
        increase the weight by 0.001.
    */
    for(int x = 0; x<10; x++){
        for(int y = 0; y<10; y++){
            for(int xx = 0; xx<10; xx++){
                for(int yy = 0; yy<10; yy++){
                    if(Brain[y][x]!=Brain[yy][xx]){
                        // should be different
                        if(Image[y][x]==Image[yy][xx]){
                            LinkWeights[y][x][yy][xx] += 0.001;
                        }
                    }else{
                        // should be the same
                        if(Image[y][x]!=Image[yy][xx]){
                            LinkWeights[y][x][yy][xx] -= 0.001;
                        }
                    }
                }
            }
        }
    }
}

void DayDream(int seconds) {
    for(int i = 0; i<seconds; i++){
        /*
            Every second, we pick a random pixel Brain[y][x]
            and calculate the total influence of all other pixels
            by iterating through x2, y2
            If Brain[y2][x2] is 1, add LinkWeights[y][x][y2][x2] to the influence
            If Brain[y2][x2] is 0, subtract LinkWeights[y][x][y2][x2] from the influence
            Let Brain[y][x] be 1 with probability 1 / (1 + exp(-influence)), zero otherwise
        */
        uniform_int_distribution<int> intd(0, 9);
        int y = intd(engine);
        int x = intd(engine);
        double influence = 0;
        for(int yy = 0; yy<10; yy++){
            for(int xx = 0; xx<10; xx++){
                if(Brain[yy][xx]) influence += LinkWeights[y][x][yy][xx];
                else influence -= LinkWeights[y][x][yy][xx];
            }
        }
        uniform_real_distribution<double> dist(0.0, 1.0);
        double prob = (double)1 / (1+exp(-1*influence));
        double temp = dist(engine);
    //    cout<<prob<<" "<<temp<<endl;
        if(temp<=prob){
            Brain[y][x] = 1;
        }else{
            Brain[y][x] = 0;
        }
    }
}

int main() {
    int MRI[10][120];
    for (int day = 0; day < 1000; day++){
        /*
            Watch digit 0 and dream for 10000 seconds
            Watch digit 1 and dream for 10000 seconds
        */
        WatchImage(DigitZero);
        DayDream(10000);
        WatchImage(DigitOne);
        DayDream(10000);
        WatchImage(DigitTwo);
        DayDream(10000);
        WatchImage(DigitThree);
        DayDream(10000);
        WatchImage(DigitFour);
        DayDream(10000);
        WatchImage(DigitFive);
        DayDream(10000);
        // Take a MRI scan of the brain
        for (int y = 0; y < 10; y++) {
            MRI[y][12 * (day%10)] = 0;
            for (int x = 0; x < 10; x++) {
                MRI[y][12 * (day%10) + x + 1] = Brain[y][x];
            }
            MRI[y][12 * (day%10) + 11] = 1;
        }
        // print if we have 10 MRI scans
        if (day % 10 == 9) {
            cout << "day" << day << endl;
            for (int y = 0; y < 10; y++) {
                for (int x = 0; x < 120; x++) {
                    cout << (MRI[y][x] ? '#' : ' ');
                }
                cout << endl;
            }
            cout << endl;
        }
    }
}
