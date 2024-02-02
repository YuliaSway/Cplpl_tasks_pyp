#include <bitset>
#include <iostream>

// инкремент, проверить ???:
int a = 0;
{
	int result = ++a; // prefix increment
	// a += 1;
	// result = a;
	// result = 1;
}
{
	int result = a++; // postfix increment, подороже будет, рекомендовано использовать prefix increment
	// result = a;
	// a += 1;
	// result = 1;
}

int main(int, char *[]) {
	// 1. Arithmetic progression sum
	const int n_size = 10;
	int sum = 0;

	for (int i = 0; i < n_size; ++i) {
		std::cout << i << " ";
		sum += i;
	}
	std::cout << "\nsum : " << sum << std::endl;

	// 3.
	int i = 0;
	for (;;) {  // можно частично указывать, например, for ( ; i < n_size; )
		if (++i > 100)
			break;
	}
	std::cout << "i = " << i << std::endl;

	for(int i : array){
		// ??? с простыми типами не используется
	}

	// 4. Overflow
	int j = 0;
	for (std::size_t k = 100; k >= 0; k += 3) {
		std::bitset<32> buffer(k);
		std::cout << k << " ";
		std::cout << buffer << std::endl;
		;
		if (++j > 104)
			break;
	}

	// 5. Continue
	for (int i = 0; i < 10; ++i) {
		if (i % 2) {
			std::cout << "start next iteration for i = " << i << std::endl;
			continue;
		}

		std::cout << " full loop iteration " << i << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
