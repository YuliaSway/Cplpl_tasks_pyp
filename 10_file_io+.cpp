#include <fstream>
#include <iostream>
#include <string>

int main(int, char *[]) {
	std::fstream fso; // объявление переменной
	fso.open("ex_file.txt", std::fstream::out); //| std::fstream::app); // открыть файл на запись - out
	// можно файл открыть и на запись и на чтение, но нужно следить за курсором

	fso << " This 12 34 is a simple example of file output" << std::endl; // в файл записываем строку
	fso << " One more line";
	
	
	fso.close();

	std::string single_world, w2;
	int a, b;

	std::fstream fsi;
	fsi.open("ex_file.txt", std::fstream::in); // считываем из файла

	fsi >> single_world; // из файла в какую-то переменную читаем значение
	fsi >> a >> b; // ??? 
	fsi >> w2;

	fsi.close();

	std::cout << single_world << std::endl;
	std::cout << a << " " << b << std::endl;
	std::cout << w2 << std::endl;

	// 2. Print file content
	fsi.open("ex_file.txt", std::fstream::in);
	std::string line;
	while (std::getline(fsi, line))
		std::cout << line << std::endl;
	fsi.close();

	return 0;
}
