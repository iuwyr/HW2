#include <iostream>
#include "equation_funcs.hh"
#include "byte_funcs.hh"
#include "keygen_func.hh"

using namespace std;

int main(int argc, char* argv[]) {
    string file_name = argv[1];
    generateKey(file_name);
}