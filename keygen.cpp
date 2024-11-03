#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

void shiftOdds(int &a, int &b, int &c, int d) {
    c = b;
    b = a;
    a = (d % 13) - (d % 6);
}

int disriminant(int a, int b, int c) {
    return (b*b - 4 * a * c);
}

uint8_t createByte(int &a, int &b, int &c) {
    string byte_string = "";
    int d;

    for (int i = 0; i < 8; i++) {
        d = disriminant(a, b, c);
        if (d % 2 == 0) byte_string += "0"; else byte_string += "1";
        shiftOdds(a, b, c, d);
    }

    uint8_t byte = static_cast<uint8_t> (bitset<8>(byte_string).to_ulong());
    return byte;
}

void generateKey(string file_name) {
}

int main(int argc, char* argv[]) {
    string file_name = argv[1];
    generateKey(file_name);
}