#ifndef BYTE_FUNCS_HH
#define BYTE_FUNCS_HH

#include <vector>
#include <string>
#include <bitset>

using namespace std;

uint8_t createByte(int &a, int &b, int &c);
void writeBytesToFile(const vector<uint8_t> &byte_vector, const string &file_name);

#endif