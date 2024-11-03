#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <sstream>

using namespace std;

void shiftOdds(int &a, int &b, int &c, int d) {
    c = b;
    b = a;
    a = (d % 13) - (d % 6);
}

int disriminant(int a, int b, int c) {
    return (b*b - 4 * a * c);
}