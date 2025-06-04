#include "ceasar_encryption.h"

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