#include <iostream>
using namespace std;

void byValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}

void byReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

void byPointer(long long* fee, int percent) {
    *fee -= *fee * percent / 100;
}

void change(int a, int& b, int* c) {
    a += 10;
    b += 10;
    *c += 10;
}

int& bigger(int& p, int& q) {
    return p > q ? p : q;
}

void show(int x, int y = 5, int z = 10) {
    cout << x + y + z << ' ';
}

int main() {
    cout << "PART 1: Concession methods\n";
    long long a = 45000, b = 45000, c = 45000;

    byValue(a, 10);
    byReference(b, 10);
    byPointer(&c, 10);

    cout << "Call by value: " << a << '\n';
    cout << "Call by reference: " << b << '\n';
    cout << "Call by pointer: " << c << '\n';

    cout << "\nPART 2: Predict the output\n";
    int x = 1, y = 2, z = 3;
    change(x, y, &z);
    cout << x << ' ' << y << ' ' << z << '\n';

    bigger(x, z) = 100;
    cout << x << ' ' << z << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << '\n';
    return 0;
}