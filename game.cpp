#include <iostream>
#include <string>

#include "set_value.h"
#include "input_user_value.h"
#include "records_file.h"

// обработка входных параметров при запуске приложения
// true - играем
// false - вывести только таблицу результатов
bool check_parameters(char *argv[], int &max_range){
    std::string str, str_v; 
    
    str = argv[1];
    str_v = "table";
    if( str == str_v){
        return false; // если вывести только таблицу результатов
    } else{
        // реализовать проверку ввода корректных значений ... но ...
        //std::string str;
        str = argv[1];
        max_range = std::stoi(str);
        return true;
    }
    
}

int main(int argc, char *argv[]){

    if(argc = 2){

        int max_range; //int max_range = 100; // задаем максимально допустимое значение диапазона генерации чисел 
        bool play = check_parameters(argv, max_range);
        
        if(play){
            std::cout << "- - - Game start" << argc << std::endl;
            int random_value = set_value(max_range);
            //std::cout << "(main) random_value = " << random_value << std::endl;

            user_start_game(random_value, max_range);
            std::cout << "- - - Your Game is Over :) !" << std::endl;
        }


        // Вывод таблицы результатов:
        std::cout << "Show record table ? (y/n): ";
        std::string y_n;
        std::cin >> y_n;
        if(!std::cin.fail() && y_n == "y"){
            std::cout << "High scores table: \n";
            file_read();
        }
    } else {
        std::cerr << "Incorrent input parameter !" << std::endl;
    }
    return 0;
}