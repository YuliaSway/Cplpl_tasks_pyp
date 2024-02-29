#include <string>
#include <fstream>
#include <iostream>

std::string file_name = "logs.txt";

void file_write(const std::string &str){
    std::ofstream file(file_name, std::ios::app);
    if(file.is_open()){
        file << str << std::endl;    
        file.close();
    }
    
}

void file_read(){
    std::ifstream file(file_name);
    if(file.is_open()){

        std::string line;

        while(std::getline(file, line)){
            std::cout << line << std::endl;
        }   
        file.close();
    }
}
