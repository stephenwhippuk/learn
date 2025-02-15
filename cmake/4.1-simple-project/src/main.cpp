#include <iostream>
#include "lib.h"
using namespace std;

int main(){
    cout << "Please Enter Your Name: ";
    auto name = lib::readLine();
    lib::printGreet(name);
}