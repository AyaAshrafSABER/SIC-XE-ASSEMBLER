#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <iostream>

using namespace std;

class Converters
{
    public:
        Converters();
        int convertToDecimal(string);
        string convertToHexa(int);
    private:
        string convertCharToString(char[], int);
};

#endif // CONVERTERS_H
