#include <iostream>
#include "print.h"

void lib::printGreet(const std::string& name){
    std::cout << "Hello " << name << std::endl;
}