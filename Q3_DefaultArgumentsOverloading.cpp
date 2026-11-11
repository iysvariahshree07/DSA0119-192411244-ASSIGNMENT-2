#include <iostream>
using namespace std;

struct Parcel {
    double weight;
};

void charge(double kg, bool express = false, bool insured = false) {
    cout << "Kilograms function: " << kg
         << ", Express: " << boolalpha << express
         << ", Insured: " << insured << '\n';
}

void charge(int grams) {
    cout << "Grams function: " << grams << '\n';
}

void charge(Parcel p) {
    cout << "Parcel function: " << p.weight << " kg\n";
}

int main() {
    Parcel p{3.5};

    charge(2);
    charge(2.0f);
    charge(2.0);
    charge(2.5, true);
    charge(2.5, true, true);
    charge(p);

    return 0;
}