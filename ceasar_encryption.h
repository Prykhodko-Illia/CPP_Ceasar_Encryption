#ifndef CEASAR_ENCRYPTION_H
#define CEASAR_ENCRYPTION_H

extern "C" {
    __declspec(dllexport) char *encrypt(char *rawText, int key);

    __declspec(dllexport) char *decrypt(char *encryptedText, int key);
}
#endif //CEASAR_ENCRYPTION_H
