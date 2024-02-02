#include <iostream>

using std::cout;
using std::endl;

int sum_array(int* array2, int size){
    // * - указатель, техническая переменная , которая в качестве своего значения имеет адрес другой переменной (variable)
    // указатель на адрес начала массива в оперативной памяти , адрес в 16-тиричной системе счисления (0x0ABE12302)
    // size - количество элементов в массиве
    // у всех переменных любого типа адреса представляются идентично
    // int* - т.к. любая переменная должна быть типизирована, то должен быть указан тип и для указателя
    // нельзя без size, т.к. указатель - на адрес массива, который не содержит метаинформации о длине массива
    int result = 0;
    for(int i = 0; i < size; ++i){
        result += array2[i];
        // эквивалент, *() - раз'именовать ???
        // result = result + *(array2 + i);
    }
    return result;

    // sizeof(int*) == 8 byte; // в 64-битной системе, этот размер достаточен для хранения адреса первого элемента массива
    // указатель поддерживает арифметику указателей, например можно получить адрес 23ого элемента массива:
    // int* element = array2 + 23;

    // многомерные массивы ???

}

// есть указатели без типа: void* prt; ???
// указатель на строку: std::string* prt_str; 
// в C++ есть ссылки, нужны в функциях, разбор на сл.занятиях ???

int main() {

    int array[] = {1, 2, 3, 4, 5};
    int array2[10]; // статический массив с определенным размером
    // нумерация индексов с нуля
    array[1] = 24; // {1, 24, 3, 4, 5}

    // character array is a C-style string
    char paul[] = "Paul";

    cout << paul << endl;

    for (int i = 0; i < 4; ++i) {
        cout << paul[i] << ' ';
    }
    cout << endl;

    // '\0' - null terminator
    // | P | a | u | l | \0 |
    for (int i = 0; paul[i] != '\0'; ++i) {
        cout << paul[i] << ' ';
    }
    cout << endl;

    // noncharacter arrays
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27};
    const int nprimes = sizeof(primes) / sizeof(primes[0]);
    for (int i = 0; i < nprimes; ++i) {
        cout << primes[i] << ' ';
    }
    cout << endl;


    // pointers
    for (char* p = paul; *p != '\0'; ++p) {
        cout << *p << ' ';
    }
    cout << endl;

    // string length (strlen)
    int paul_len = 0;
    for (char *p = paul; *p != '\0'; ++p) {
        ++paul_len;
    }
    cout << "paul name length: " << paul_len << endl;

    // string copy (strcpy)
    char name[80];
    char *src = paul;
    char *dst = name;
    do {
        *dst++ = *src++;
    } while (*src != '\0');
    *dst = '\0';
    cout << name << endl;
}