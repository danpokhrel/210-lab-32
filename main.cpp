// COMSC-210 | Lab 32 | Dan Pokhrel
#include "Car.h"
#include <iostream>
#include <deque>
#include <random>
using namespace std;

const int PROB_ENTER = 45;
const int START_CARS = 2;

// Prototypes
bool probability(int percent);
void print_cars(deque<Car> &booth);

int main(){
    srand(time(0));
    deque<Car> booth;

    // Initialize tool booth
    for (int i = 0; i < START_CARS; i++)
        booth.push_back(Car());
    cout << "Initial Queue:\n";
    print_cars(booth);
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

void print_cars(deque<Car> &booth){
    if (booth.size() == 0)
        cout << "<Empty>";
    for (auto car : booth)
        car.print();
}

bool probability(int percent){
    int x = rand() % 100;
    return x < percent;
}