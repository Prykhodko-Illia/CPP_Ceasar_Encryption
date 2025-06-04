#include <iostream>
#include <windows.h>

int main() {
    typedef char *(*encrypt_t)(char *, int);
    typedef char *(*decrypt_t)(char *, int);

    HINSTANCE handle = LoadLibrary(TEXT("..//ceasar_encryption.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE) {
        std::cout << "Lib not found" << std::endl;
        return 1;
    }

    encrypt_t encrypt = (encrypt_t)GetProcAddress(handle, TEXT("encrypt"));
    if (encrypt == nullptr) {
        std::cout << "The function is not found";
        return 1;
    }

    decrypt_t decrypt = (decrypt_t)GetProcAddress(handle, TEXT("decrypt"));
    if (decrypt == nullptr) {
        std::cout << "The function is not found";
        return 1;
    }

    char *someText = new char[50];
    int key;
    std::cout << "Write text to encode: " << std::endl;
    std::cin.getline(someText, 50);

    std::cout << "Write an encryption key: " << std::endl;
    std::cin >> key;

    std::cout << encrypt(someText, key) << std::endl;
    std::cout << decrypt(someText, key) << std::endl;

    delete[] someText;
    FreeLibrary(handle);
    return 0;
}