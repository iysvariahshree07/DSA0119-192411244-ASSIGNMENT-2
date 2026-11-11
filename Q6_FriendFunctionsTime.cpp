#include <iostream>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;

    return (first > second) ? first - second : second - first;
}

bool earlier(const Time& a, const Time& b) {
    return (a.h * 60 + a.m) < (b.h * 60 + b.m);
}

int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    Time same1(10, 0), same2(10, 0);
    cout << "Same time difference: "
         << minutesBetween(same1, same2) << '\n';

    Time beforeNoon(11, 30), afterNoon(12, 30);
    cout << "Before noon is earlier: "
         << earlier(beforeNoon, afterNoon) << '\n';

    return 0;
}