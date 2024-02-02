#include <bitset>
#include <iostream>
#include <vector>

int main(int, char *[]) {
	int counter = 0;
	short int value = 25;
	
	// работает только с целочисленными (или числовыми ???) значениями
	// более быстро работает, нежели if, т.к. может сразу перейти на нужный case
	switch (value) {
	case 25:
		counter += 1;
		std::cout << "First case is selected\n";
		break;  // выход из свитча сразу, в отличии от использования if (разве в if нет выхода ???)
		// перейдет ли в след. case ??? если не будет breake
	case 34:
		counter += 10;
		std::cout << "Second case is selected\n";
		break;
	case 56:
		counter += 100;
		std::cout << "Third case is selected\n";
		break;
	default: // аналог else
		counter = 2000;
	}
	std::cout << " Counter is equal to: " << counter << std::endl;

	// ------------------------------------------------------------------------

	// реализация логики нажатия на мышку:
	// eNUM - перечисления, когда ограническое количество значений необходимо объединить под одним именем
	enum class MouseButtons : int { LEFT_BTN = 1,
									MIDDLE_BTN = 3,
									RIGHT_BTN = 2,
									EXTRA_BTN = 0 };
	MouseButtons mouse_btn = MouseButtons::EXTRA_BTN;
	switch (mouse_btn) {
	case MouseButtons::LEFT_BTN:
		std::cout << " Left button is pressed. Processing it ... " << std::endl;
		if (true)
			std::cout << "Operator if invocation\n";
		// Left button is pressed
		break;
	case MouseButtons::MIDDLE_BTN:
		// Middle button is pressed
		break;
	case MouseButtons::RIGHT_BTN:
		// Right button is pressed
		break;
	case MouseButtons::EXTRA_BTN:
		std::cout << " Extra button is pressed. Processing it ... " << std::endl;
		break;
		// is an option but good practice
	default:
		// Do something else if needed
		std::cout << "Dropped into default case scenario" << std::endl;
	}

	return 0;
}