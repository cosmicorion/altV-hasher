#include "hash.h"
#include <Windows.h>
#include <iostream>

int main() {
    // example

	std::cout << "Text to hash: ";
	std::string input;
	std::cin >> input;

	uint64_t result = hash(input);
	std::cout << "Hash: " << result << std::endl;

	system("pause");

    return 0;
}