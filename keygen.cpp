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

void writeBytesToFile(const vector<uint8_t> &byte_vector, const string &file_name) {
    ofstream outFile(file_name, ios::binary);

    if (file_name.substr(file_name.find_last_of('.')) == ".bin") {
        outFile.write(reinterpret_cast<const char*> (byte_vector.data()), byte_vector.size());
        cout << "Ключ записан в файл " << file_name << endl << endl;
    } 
    
    else if (file_name.substr(file_name.find_last_of('.')) == ".txt") {
        for (const uint8_t &byte : byte_vector) {
            outFile << hex << setw(2) << setfill('0') << static_cast<int>(byte);
        }
        cout << "Ключ записан в файл " << file_name << endl << endl;
    } 
    
    else {
        cout << "Неподдерживаемое расширение файла: " << file_name << endl << endl;
    }

    outFile.close();
}

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

int main(int argc, char* argv[]) {
    string file_name = argv[1];
    generateKey(file_name);
}