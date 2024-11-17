// COMSC-210 | Lab 33 | Dan Pokhrel
#include "Car.h"
#include <iostream>
#include <deque>
#include <random>
#include <array>
using namespace std;

const int PROB_ENTER = 45;
const int START_CARS = 2;
const int LANES = 4, ITER = 20;

// Prototypes
bool probability(int percent);
void print_cars(array<deque<Car>, LANES> &plaza);

int main(){
    srand(time(0));
    array<deque<Car>, LANES> plaza;

    // Initialize tool booths
    for (int l = 0; l < LANES; l++)
    for (int i = 0; i < START_CARS; i++)
        plaza[i].push_back(Car());
    cout << "Initial Queue:\n";
    print_cars(plaza);
    cout << endl;

    // Simulate
    int i = 0;
    while (booth.size() > 0){
        i++;
        cout << "Time: " << i << endl;
        cout << "Operation: ";
        if (probability(PROB_ENTER)){
            auto car = Car();
            booth.push_back(car);
            cout << "Joined Lane - "; car.print();
        }
        else{
            auto car = booth.front();
            booth.pop_front();
            cout << "Car Payed - "; car.print();
        }
        cout << "Queue:\n";
        print_cars(booth);
        cout << endl;
    }

    return 0;
}

void print_cars(array<deque<Car>, LANES> &plaza){
    for (int l = 0; l < LANES; l++){
        cout << "Lane " << l << ":\n";
        auto booth = plaza[l];
        
        if (booth.size() == 0)
            cout << "<Empty>";
        for (auto car : booth)
            car.print();
    }
}

bool probability(int percent){
    int x = rand() % 100;
    return x < percent;
}