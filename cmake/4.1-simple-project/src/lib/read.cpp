#include <iostream>
#include "read.h"
std::string lib::readLine(){
    std::string retVal = "";
    std::cin >> retVal;
    return retVal;
}