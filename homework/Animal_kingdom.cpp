#include <bits/stdc++.h>
#define frabbit(i, nRabbit) for(int i=0;i<nRabbit;i++)
#define ftiger(i, nTiger) for(int i=0;i<nTiger;i++)
/**#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
**/
using namespace std;

const int dx[5] = {1, -1, 0, 0, 0};
const int dy[5] = {0, 0, 1, -1, 0};
const int maxx = 200;
const int maxy = 100;
int nRabbit = 0;
int nTiger = 0;
vector<vector<set<int> > > rbtfield(maxy, vector<set<int> >(maxx));
vector<vector<set<int> > > tgfield(maxy, vector<set<int> >(maxx));

class Animal {
public:
    // member variables
    // age, health, and coordinate
    int age; int health; int x, y;int index;
    // constructor and destructor
    //
      //Define several constructors and a destructor.
      //For if coordinates are not given, set them to rand() % 50
     
    Animal(int coordsx, int coordsy, int iage, int hp, int idx) {
        x = coordsx; y = coordsy; age = iage; health = hp; index = idx;
    }
    Animal(int iage, int hp, int idx){
        x = rand()%50; y = rand()%50;
        age = iage; health = hp; index = idx;
    }
    ~Animal(){}
    // other member functions
    //
     // Each day, each animal moves in a random direction by 1 unit,
     //or is doesn't move; use rand() % 5.
     //Its age and health change, too
     //
    void move(bool type) {
        age++; health--;
        int d = rand()%5;
        int newx = x+dx[d];
        int newy = y+dy[d];
        if(newx < 0) newx = maxx-1;
        else if (newx > maxx-1) newx = 0;
        if(newy < 0) newy = maxy-1;
        else if (newy > maxy-1) newy = 0;
        if(type){
            tgfield[y][x].erase(index);
            tgfield[newy][newx].insert(index);
        }else{
            rbtfield[y][x].erase(index);
            rbtfield[newy][newx].insert(index);
        }
        x = newx;
        y = newy;
        //0 if rabbit, 1 if tiger
        
        return;
        
    }
    void aging() {
        age++; health--;
    }
};
class Rabbit : public Animal {
public:
    // constructors and destructor
    Rabbit(int coordsx, int coordsy, int iage, int hp, int idx): Animal(coordsx, coordsy, iage, hp, idx){

    };
    Rabbit(int idx): Animal(0, 100, idx){
    };
    Rabbit(): Animal(0, 100, 0){}
    ~Rabbit(){}
    // other member functions
    bool IsReady() {
        // A rabbit is ready to reproduce every 10 days
        return age%10==0&&age!=0;
    }
    Rabbit Reproduce() {
        // Rabbit baby has health 100
        Rabbit baby = Rabbit(x,y,0,100, nRabbit);
        rbtfield[y][x].insert(nRabbit);
        return baby;
    }
};
class Tiger : public Animal {
public:
    // constructors and destructor
    Tiger(int coordsx, int coordsy, int iage, int hp, int index): Animal(coordsx, coordsy, iage, hp, index){

    }
    Tiger(int index): Animal(0, 100, index){
    }
    Tiger(): Animal(0, 100, 0){}
    ~Tiger(){}
    // other member functions
    bool IsReady() {
        if(health>100) return 1;
        else return 0;
        // A tiger is ready to reproduce if health > 100
    }
    Tiger Reproduce() {
        // Mother tiger gives half of her health to the baby
        
        Tiger baby = Tiger(x, y, 0, health/2, nTiger);
        tgfield[y][x].insert(nTiger);
        health-=health/2;
//        nTiger++;
        return baby;
    }
    void eat(Rabbit& R) {
        // Eating 1 rabbit regenerates 5 health
        R.health = 0;
        health+=5;
    }
};
Rabbit R[1000000 + 100];
Tiger T[1000000 + 100];
void InitializeAnimals() {
    // Start with 1000 rabbits and 200 tigers.
    for(int i = 0; i<1000; i++){
        R[i] = Rabbit(i);
        nRabbit++;
        rbtfield[R[i].y][R[i].x].insert(i);
    }
    for(int i = 0; i<200; i++){
        T[i] = Tiger(i);
        tgfield[T[i].y][T[i].x].insert(i);
        nTiger++;
    }
    cout<<"Initialization completed"<<endl;
}

void AnimalMove() {
    for(int i = 0; i<nRabbit; i++){
        R[i].move(0); 
    }
    for(int i = 0; i<nTiger; i++){
        T[i].move(1);
    }
}
void RabbitReproduce() {
    int nRabbitc = nRabbit;
    frabbit(i, nRabbitc){
        if(!R[i].IsReady()) continue;
        R[nRabbit] = R[i].Reproduce();
        nRabbit++;
    }
}
void TigerReproduce() {
    int nTigerc = nTiger;
    ftiger(i, nTigerc){
        if(!T[i].IsReady()) continue;
        T[nTiger] = T[i].Reproduce();
        nTiger++;
    }
}
void TigerEatRabbit() {
    ftiger(i, nTiger){
        Tiger& curT = T[i];
        for(int rabbitidx: rbtfield[curT.y][curT.x]){
            R[rabbitidx].health = 0;
            curT.health+=5;
        }
        rbtfield[curT.y][curT.x].clear();
    }
}
void RabbitDie() {
    if(nRabbit<=0) return;
    //
    //  Rabbit dies if
    // 1. it is older than 50 days
    // 2. it is eaten by a tiger
    // 3. There are five rabbits in the same cell
    int nc = nRabbit;
    frabbit(i, nRabbit){
        if(rbtfield[R[i].y][R[i].x].size()>=10){
            for(int index:rbtfield[R[i].y][R[i].x]){
                R[index].health = 0;
            }
        }else
        if(R[i].age>50){
            R[i].health = 0;
        }
    }
    frabbit(i, nRabbit){
        if(R[i].health == 0){
            rbtfield[R[i].y][R[i].x].erase(R[i].index);
            rbtfield[R[nRabbit-1].y][R[nRabbit-1].x].erase(R[nRabbit-1].index);
            rbtfield[R[nRabbit-1].y][R[nRabbit-1].x].insert(R[i].index);
            swap(R[i].index, R[nRabbit-1].index);
            swap(R[i], R[nRabbit-1]);
            
            nRabbit--;
            i--;
        }
    }
    
}
void TigerDie() {
    // Tiger dies if health = 0
    int nTigerc = nTiger;
    if (nTigerc<=0) return;
    ftiger(i, nTiger){
        if(T[i].health <= 0){
            tgfield[T[i].y][T[i].x].erase(T[i].index);
            tgfield[T[nTiger-1].y][T[nTiger-1].x].erase(T[nTiger-1].index);
            tgfield[T[nTiger-1].y][T[nTiger-1].x].insert(T[i].index);
            swap(T[i].index, T[nTiger-1].index);
            swap(T[i], T[nTiger-1]);
            nTiger--;
            i--;
        }
    }cout<<endl;
}

void VisualizeField(int day) {
    // create field
    char Field[maxy][maxx];
    // Put a '#' for each Tiger and a '.' for each Rabbit.
    printf("\x1b[H");
    for(int i = 0; i<maxy; i+=2){
        for(int j = 0; j<maxx; j++){
            if(!tgfield[i][j].empty()){
                cout<<'#';
            }else{
                if(!rbtfield[i][j].empty()){
                    cout<<'.';
                }else{cout<<' ';}
            }
        }cout<<endl;
    }
    cout << day << " days  " << nRabbit << " Rabbits  " << nTiger << " Tigers  " << endl;
    //for (int i = 0; i < sqrt(nRabbit) && i < 400; i++) cout << ".";
    //cout << endl;
    //for (int j = 0; j < sqrt(nTiger) && j < 400; j++) cout << "#";
    //cout << endl;
    // sleep or 500 milliseconds, 50 if you have a decent laptop
    this_thread::sleep_for(chrono::milliseconds(50));
}


int main() {
    InitializeAnimals();
    cout<<"ok";
    frabbit(i, nRabbit){
        R[i].index = i;
    }
    ftiger(i, nTiger){
        T[i].index = i;
    }
//    srand(time(NULL));
srand(1);
    // Main loop
    for (int day = 0; day < 10000000; day++) {
        // break if no rabbit or tiger left
        if(nRabbit<=0||nTiger<=0) break;
        AnimalMove();
        RabbitReproduce();
        TigerReproduce();
        TigerEatRabbit();
        RabbitDie();
        TigerDie();
                
        if (day % 1 == 0) VisualizeField(day);
        for(auto ttt: tgfield[99][1]) cout<<ttt<<" ";
        cout<<endl;
        cout<<T[556].x<<" "<<T[556].y<<" "<<T[556].health<<" "<<T[556].index<<endl;
    }
}


