#include <iostream>
#include <string>

#include "set_value.h"
#include "input_user_value.h"
#include "records_file.h"

// обработка входных параметров при запуске приложения
// возвращает:
// 1 - играем
// 0 - вывести только таблицу результатов
// -1 - ошибка в переданных агрументах
int check_parameters(char *argv[], const int argc, int &max_range){
    
    if(argc == 1){
        max_range = 100;
        return 1; // при вызове не заданы параметры, играем с макс.значением до 100
    }
    if(argc == 2){
        //std::string argv_v = argv[1];
        if(std::strcmp(argv[1],"-table") == 0){
            return 0; // получить таблицу результатов
        }else{
            try{
                max_range = std::stoi(argv[1]); // второй параметр число
                if(max_range < 0){
                    return -1;
                }
                return 1;
            }
            catch(const std::invalid_argument& ia){
                std::cerr << "Incorrect argument: " << ia.what() << std::endl;
                return -1; 
            }
            catch(const std::exception& ex){
                std::cerr << "Undefines error: " << ex.what() << std::endl;
                return -1;
            }
        }
    }
    return -1;
    
    
}

int main(int argc, char *argv[]){

    
    int max_range; //int max_range = 100; // задаем максимально допустимое значение диапазона генерации чисел 
    int play = check_parameters(argv, argc, max_range);
        
    if(play == 1){
        int random_value = set_value(max_range);
        user_game(random_value, max_range);
    } else if(play == 0){
        std::cout << "High scores table: \n";
        file_read();
    } else{
        std::cerr << "Incorrect input argument" << std::endl;
        return -1;
    }

    return 0;
}