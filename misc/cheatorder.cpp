#include <bits/stdc++.h>
using namespace std;

struct Order{
    int id;
    string name;
    int num;
    Order* next;
    Order* previous;
};

int main(){

    int choice;
    //uses id
    map<int, Order> Os;
    *Order head;
    *Order tail;
    int id, quant; string name;
    while(1){
        cin>>choice;
        switch(choice):
        case 1:
            cin>>id>>name>>quant;
            Order* nO = new Order{id,name,quant,nullptr,tail};
            if(head==nulptr) head = nO;
                Os[id] = nO;
    }
}
