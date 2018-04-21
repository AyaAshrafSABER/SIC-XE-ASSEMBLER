#include "Converters.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>

using namespace std;

string Converters::convertToHexa(int decimalNumber) {
    char hexaNumber[15];
    int hexaLength = 0;
    while (decimalNumber != 0) {
        int modNumber = decimalNumber % 16;
        if (modNumber < 10) {
            modNumber = modNumber + 48;
        } else {
            modNumber = modNumber + 55;
        }
        hexaNumber[hexaLength] = modNumber;
        decimalNumber /= 16;
        hexaLength++;
    }
    string result = convertCharToString(hexaNumber, hexaLength);

    return result;

}

int Converters::convertToDecimal(string hexaNumber) {
    std::istringstream converter(hexaNumber);
    unsigned int value;
    converter >> std::hex >> value;
    return value;
}

string Converters::convertCharToString(char hexaNumber[], int hexaLength) {
    char newChar[hexaLength];
    int counter = 0;
    for (int i = hexaLength - 1; i >= 0; i--) {
        newChar[counter++] = hexaNumber[i];
    }
    newChar[counter] = '\0';
    string result(newChar);
    return result;
}
