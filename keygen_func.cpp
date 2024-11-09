#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <sstream>
#include "equation_funcs.hh"
#include "byte_funcs.hh"
#include "keygen_func.hh"

using namespace std;

void generateKey(string file_name) {
    int a, b, c, length;
    vector<uint8_t> byte_vector;

    cout << endl << "Введите длину ключа в байтах: ";
    cin >> length;
    cout << "Введите коэффиценты квадратного уравнения ax^2 + bx + c = 0 через пробел: ";
    cin >> a >> b >> c;
    cout << endl;

    for (int i = 0; i < length; i++) {
        uint8_t byte = createByte(a, b, c);
        byte_vector.push_back(byte);
    }

    cout << "Сгенерированный ключ: ";
    for (uint8_t byte: byte_vector) {
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << static_cast<int>(byte);
        cout << ss.str() << " ";
    }
    cout << endl << endl;

    writeBytesToFile(byte_vector, file_name);
}