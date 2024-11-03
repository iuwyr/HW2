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

uint8_t createByte(int &a, int &b, int &c) {
    string byte_string = "";

    for (int i = 0; i < 8; i++) {
        int d = disriminant(a, b, c);
        if (d % 2 == 0) byte_string += "0"; else byte_string += "1";
        shiftOdds(a, b, c, d);
    }

    uint8_t byte = static_cast<uint8_t> (bitset<8>(byte_string).to_ulong());
    return byte;
}

void generateKey(string file_name) {
    int a, b, c, length;
    vector<uint8_t> byteVector;

    cout << endl << "Введите длину ключа в байтах: ";
    cin >> length;
    cout << "Введите коэффиценты квадратного уравнения ax^2 + bx + c = 0 через пробел: ";
    cin >> a >> b >> c;
    cout << endl;

    for (int i = 0; i < length; i++) {
        uint8_t byte = createByte(a, b, c);
        byteVector.push_back(byte);
    }

    cout << "Сгенерированный ключ: ";
    for (uint8_t byte: byteVector) {
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << static_cast<int>(byte);
        cout << ss.str() << " ";
    }
    
    cout << endl << endl;
    cout << "Ключ записан в файл " << file_name << endl << endl;
}

int main(int argc, char* argv[]) {
    string file_name = argv[1];
    generateKey(file_name);
}