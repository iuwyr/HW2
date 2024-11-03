#ifndef FUNCS_HH
#define FUNCS_HH

#include <vector>
#include <string>
#include <bitset>

using namespace std;

int mod(int a, int b);
void shiftOdds(int &a, int &b, int &c, int d);
int disriminant(int a, int b, int c);
uint8_t createByte(int &a, int &b, int &c);
void writeBytesToFile(const vector<uint8_t> &byte_vector, const string &file_name);
void generateKey(string file_name);

#endif