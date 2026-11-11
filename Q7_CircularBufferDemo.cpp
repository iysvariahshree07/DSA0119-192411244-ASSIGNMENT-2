#include <iostream>
using namespace std;

class TransactionBuffer {
private:
    static const int SIZE = 10;
    double values[SIZE];
    int start;
    int count;

public:
    TransactionBuffer() : start(0), count(0) {}

    void add(double amount) {
        if (count < SIZE) {
            int position = (start + count) % SIZE;
            values[position] = amount;
            ++count;
        } else {
            values[start] = amount;
            start = (start + 1) % SIZE;
        }
    }

    void display() const {
        cout << "Latest transactions:\n";
        for (int i = 0; i < count; i++) {
            int position = (start + i) % SIZE;
            cout << values[position] << '\n';
        }
    }
};

int main() {
    TransactionBuffer buffer;

    for (int i = 1; i <= 12; i++) {
        buffer.add(i * 100);
    }

    buffer.display();
    return 0;
}