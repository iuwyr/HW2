#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include "byte_funcs.hh"
#include "equation_funcs.hh"

using namespace std;

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