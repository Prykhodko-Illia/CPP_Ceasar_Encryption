#include "ceasar_encryption.h"
#include <iostream>

char *encrypt(char *rawText, int key) {
    for (int i = 0; rawText[i] != '\0'; i++) {
        rawText[i] = char(int(rawText[i]) + key);
    }
    return rawText;
};

char *decrypt(char *encryptedText, int key) {
    for (int i = 0; encryptedText[i] != '\0'; i++) {
        encryptedText[i] = char(int(encryptedText[i]) - key);
    }
    return encryptedText;
}

void printText(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        std::cout << text[i];
    }
}

int main() {
    char *someText = new char[50];
    std::cin.getline(someText, 50);
    int key = 205;

    encrypt(someText, key);
    printText(someText);
    std::cout << std::endl;

    decrypt(someText, key);
    printText(someText);

    delete[] someText;
}