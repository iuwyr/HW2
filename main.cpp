#include <iostream>
#include "funcs.hh"

using namespace std;

int main(int argc, char* argv[]) {
    string file_name = argv[1];
    generateKey(file_name);
}