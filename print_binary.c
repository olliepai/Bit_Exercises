#include <stdio.h>

//1. Complete the functions below so that they print the individual bits of the passed in argument.
//   Use the main function to test them.

void print8BitBinary(unsigned char v){
    int iterator = 7;

    for (int i = 128; i >= 2; i = i / 2) {
        unsigned char digit = (v & i) >> iterator;
        printf("%i", digit);
        iterator = iterator - 1;
    }

    unsigned char firstDigit = v & 1;
    printf("%i", firstDigit);
}

void print16BitBinary(unsigned short v){
    unsigned char *byte = (unsigned char*)&v + 1;
    print8BitBinary(*byte);
    byte--;
    print8BitBinary(*byte);
}

void print32BitBinary(unsigned int v){
    unsigned short *byte = (unsigned short*)&v + 1;
    print16BitBinary(*byte);
    byte--;
    print16BitBinary(*byte);
}

void print64BitBinary(unsigned long v){
    unsigned int *byte = (unsigned int*)&v + 1;
    print32BitBinary(*byte);
    byte--;
    print32BitBinary(*byte);
}

int main(int argc, char** argv){
    print32BitBinary(300);

    return 0;
}