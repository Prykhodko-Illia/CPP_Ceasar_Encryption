#include <iostream>
#include "ceasar_encryption.h"

int main() {
    char *someText = new char[50];
    int key;
    std::cout << "Write text to encode: " << std::endl;
    std::cin.getline(someText, 50);

    std::cout << "Write an encryption key: " << std::endl;
    std::cin >> key;

    std::cout << encrypt(someText, key) << std::endl;
    std::cout << decrypt(someText, key) << std::endl;

    delete[] someText;
    return 0;
}