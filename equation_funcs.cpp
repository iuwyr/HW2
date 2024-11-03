#include <iostream>
#include "funcs.hh"

using namespace std;

int mod(int a, int b) {
    int result = a % b;
    if (result < 0) {
        result += abs(b);
    }
    return result;
}

void shiftOdds(int &a, int &b, int &c, int d) {
    c = b;
    b = a;
    a = mod(d, 13) - mod(d, 6);
}

int disriminant(int a, int b, int c) {
    return (b*b - 4 * a * c);
}