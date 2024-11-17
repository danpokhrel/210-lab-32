// COMSC-210 | Lab 33 | Dan Pokhrel
#include "Car.h"
#include <iostream>
#include <deque>
#include <random>
#include <array>
using namespace std;

const int PROB_ENTER = 39, PROB_LEAVE = 46, PROB_SHIFT = 15;
const int START_CARS = 2;
const int LANES = 4, ITER = 20;

// Prototypes
int probability3(int perX, int perY, int perZ);
void print_cars(deque<Car> &booth);

int main(){
    srand(time(0));
    deque<Car> plaza[LANES];

    // Initialize tool booths
    for (int l = 0; l < LANES; l++)
    for (int i = 0; i < START_CARS; i++)
        plaza[l].push_back(Car());

    cout << "Initial Queue:\n";
    for (int l = 0; l < LANES; l++){
        cout << "Lane " << l+1 << ":\n";
        print_cars(plaza[l]);
    }
    cout << endl;

    for (int i = 0; i < 1000; i++)
        cout << probability3(PROB_ENTER, PROB_LEAVE, PROB_SHIFT) << " ";

    // Simulate
/*     for (int i = 0; i < ITER; i++){
        cout << "Time: " << i << endl;
        for (int l = 0; l < LANES; l++){
            cout << "Lane " << l+1 << " - ";
            auto booth = plaza[l];
            if (probability(PROB_ENTER)){
                auto car = Car();
                booth.push_back(car);
                cout << "Joined: "; car.print();
            }
            else if (booth.size() > 0){
                auto car = booth.front();
                booth.pop_front();
                cout << "Payed: "; car.print();
            }
        }
        cout << endl;
    } */

    return 0;
}

void print_cars(deque<Car> &booth){
    if (booth.size() == 0)
        cout << "    <Empty>\n";
    for (auto car : booth){
        cout << "    ";
        car.print();
    }
}

int probability3(int perX, int perY, int perZ){
    int x = rand() % 100;
    int c = -1;
    if (x < perX)
        c = 0;
    else if (x < perX+perY)
        c = 1;
    else if (x < perX+perY+perZ)
        c = 2;
    return c;
}