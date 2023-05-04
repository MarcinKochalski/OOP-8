#include <iostream>
#include <array>

using namespace std;

class Car {
public:
    Car();
    Car(unsigned i, const string& n, char power, float price);
    string getName() const;
    float getPrice() const;
    char getPower() const;
    bool isInvalid() const;
private:
    unsigned id;
    string name;
    char power;
    float Price;
};

Car::Car() {
    id = 0;
    name = "";
    power = '\0';
    Price = 1.0;
}

Car::Car(unsigned i, const string& n, char po, float p) {
    id = i;
    name = n;
    power = po;
    Price = p;
}

string Car::getName() const {
    return name;
}

float Car::getPrice() const {
    return Price;
}

char Car::getPower() const {
    return power;
}

bool Car::isInvalid() const {
    return name.empty() ||
           power == '\0' ||
           id == 0 ||
           Price < 1 || Price > 10000000;
}

Car addCar() {
    unsigned id;
    string name;
    char power;
    float price;

    cout << "Enter car ID: ";
    cin >> id;

    cout << "Enter car name: ";
    cin >> name;

    cout << "Enter car power (D or E): ";
    cin >> power;

    cout << "Enter car price: ";
    cin >> price;

    Car s4(id, name, power, price);
    return s4;
}

void print(const Car& s) {
    cout << "Name: " << s.getName() << endl;
    if (s.getPower())
        cout << "Power: " << s.getPower() << endl;
    cout << "Price: " << s.getPrice() << endl;
}

double averagefunction(Car cars[], int size) {
    int sum = 0, j = 0;
    for (int i = 0; i < size; i++) {
        if (cars[i].getPower() == 'D') {
            sum += cars[i].getPrice();
            j++;
        }
    }
    double avg = sum / j;
    return avg;
}

int main() {
    Car s1( 1, "Volkswagen Golf TDI", 'D', 20000 ); //predefined cars
    Car s2( 2, "Tesla model S", 'E', 80000 );
    Car s3;
    cout << "Car 1:" << endl;
    print(s1);
    cout << "--------------------------------------------------" << endl;
    cout << "Car 2:" << endl;
    print(s2);
    cout << "--------------------------------------------------" << endl;
    cout << "Car 3:" << endl;
    cout << "Car name: " << s3.getName() <<endl;
    if( s3.getPower() )
        cout << "Power: " << s3.getPower() << endl;
    cout << "Price $: " << s3.getPrice() << endl;
    if( s3.isInvalid() )
        cout << "Missing some data fields in object 's3'!" << endl;
    cout << "--------------------------------------------------" << endl;
    const int max = 100;
    array<Car, max> cars = {
            Car(1, "Volkswagen Golf TDI", 'D', 20000),
            Car(2, "Tesla model S", 'E', 80000),
    };
    int numCars = 2;

    cout << "Current cars: " << endl;
    for (int i = 0; i < numCars; i++) {
        print(cars[i]);
        cout << "--------------------------------------------------" << endl;
    }

    Car newCar = addCar();
    cars[numCars++] = newCar;

    cout << "New car added: " << endl;
    print(newCar);
    cout << "--------------------------------------------------" << endl;

    double avgDiesel = averagefunction(cars.data(), numCars);
    cout << "Average price of diesel cars " << avgDiesel <<" $." << endl;

    return 0;
}