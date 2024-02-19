#include <iostream>
#include <string>
#include <exception>

#include "records_file.h"

namespace ns{
    int random_value; // загаданное приложением число
    int max_range;  // максимальное значение диапазона для ввода
    int max_input = 5; // ограничение по количество вводов чисел с экрана пользователем
}


// воод пользовательских данных и проверка корректности ввода числа (?)
int input_value(){
    std::string x;
    std::cout << "Please, input value (range 0 - " << ns::max_range << ") :";
    std::cin >> x;

    // проверяем пустая ли строка
    if(x.empty() || x[0] == '\0'){
        return -1;
    }
    else {
        // не пустая, преобразовываем в целочисленный тип
        try{
            return std::stoi(x);
        }
        catch(std::exception ex){
            std::cout << "Error convert str to int ... \n" ;
            return -1;
        }
    }


}

// основная функция ввода значений и сравнение с заданным числом
bool choose_value(int &count_input){
    bool condition_value = false;
    int inp_value; 

    while(!condition_value && count_input < ns::max_input){

        inp_value = input_value();
        ++count_input;

        if(inp_value >= 0 && inp_value <= ns::max_range){
            if(inp_value == ns::random_value){
                std::cout << "You win ! \n\n";
                condition_value = true;
                break;
            } else if(inp_value < ns::random_value){
                std::cout << "Less than ... \n";
            } else if(inp_value > ns::random_value){
                std::cout << "Greater than ... \n";
            }
        } else{
            std::cout << "Your input value is out of range, need enter new value \n";
        }

    }

    if(!condition_value){
        std::cout << "You lose ... \n\n";
    }

    return condition_value;
    
}

// начало игры пользователя
void user_start_game(const int& random_value, const int& max_range){
    ns::random_value = random_value;
    ns::max_range = max_range;
    std::string user_name;

    std::cout << "Enter your Name: ";
    std::cin >> user_name;

    int count_input = 0; // счетчик попыток
    bool state = choose_value(count_input); // попытка угадать число
    std::string result = user_name + " ";
    result = result + std::to_string(count_input); 
    result = result + (state ? " (win)" : " (lose)");

    file_write(result);

    std::cout << "User name - " << user_name << ", input count - " << count_input << " " << (state ? "(win)" : "(lose)") << std::endl;

}