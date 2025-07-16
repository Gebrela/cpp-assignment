#include <iostream>
using namespace std;

//declere variable
const int MAX = 100; //storage capacity
int id[MAX] = {0}, nextId = 1; //car id
char brand[MAX][30], model[MAX][30];
float price[MAX];
bool available[MAX];

//declere function
void addCar();
void viewCars();
void rentCar();
void returnCar();

//main function
int main() {
    int choice;
    do {
        cout <<"\nWelcome To KOLFE CAR RENTAL SYSTEM"<<endl;
        cout << "1.Add \n2.View \n3.Rent \n4.Return \n5.Exit\nChoice(1-5): ";
        cin >> choice;
        switch (choice) {
            case 1: addCar(); 
                break;
            case 2: viewCars(); 
                break;
            case 3: rentCar(); 
                break;
            case 4: returnCar(); 
                break;
            case 5: cout << "Thank You For Use KOLFE CAR RENTAL SYSTEM!\nTo Use Again Refresh The Page!"; break;
            default: cout << "Invalid.\n";
        }
    } while (choice != 5);
    return 0;
}

//menu
void addCar() { //1
    for (int i = 0; i < MAX; i++) {
        if (id[i] == 0) {
            cout << "Brand: "; cin >> brand[i];
            cout << "Model: "; cin >> model[i];
            cout << "Price: "; cin >> price[i];
            id[i] = nextId++;
            available[i] = true;
            cout << "Added ID: " << id[i] << "\n";
            return;
        }
    }
    cout << "Storage Full.\n";
}

void viewCars() { //2
    bool found = false;
    for (int i = 0; i < MAX; i++) {
        if (id[i]) {
            found = true;
            cout << "ID: " << id[i] << ", " << brand[i] << " " << model[i]
                 << ", $" << price[i] << ", " << (available[i] ? "Available\n" : "Rented\n");
        }
    }
    if (!found) cout << "No cars.\n";
}

void rentCar() { //3
    int carId, days;
    cout << "Car ID: "; cin >> carId;
    cout << "Days: "; cin >> days;
    for (int i = 0; i < MAX; i++) {
        if (id[i] == carId) {
            if (available[i]) {
                available[i] = false;
                cout << "Total: $" << price[i] * days << "\n";
            } else cout << "Already rented.\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void returnCar() { //4
    int carId;
    cout << "Car ID: "; cin >> carId;
    for (int i = 0; i < MAX; i++) {
        if (id[i] == carId) {
            if (!available[i]) {
                available[i] = true;
                cout << "Returned.\n";
            } else cout << "Already available.\n";
            return;
        }
    }
    cout << "Not found.\n";
}
