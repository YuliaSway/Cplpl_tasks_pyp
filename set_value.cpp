#include <cstdlib>
#include <ctime>
#include <iostream>
#include "time.h"

int set_value(const int& max_value){
    
    //unsigned int 
    long int time_value = static_cast<long int>(std::time(nullptr)); // convert time_t value to int
    std::srand(time_value);
    const int random_value = std::rand()%max_value;

    //std::cout << "std::time(nullptr) = " << time_value << std::endl;
    std::cout << "random_value = " << random_value << std::endl;

    return random_value;

}