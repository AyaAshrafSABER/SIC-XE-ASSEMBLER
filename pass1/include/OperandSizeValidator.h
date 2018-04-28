#ifndef OPERANDSIZEVALIDATOR_H
#define OPERANDSIZEVALIDATOR_H

using namespace std;
class OperandSizeValidator
{
    public:
        static const int TYPE_HEXA_OPERAND = 8;
        static const int TYPE_BYTE_OPERAND = 9;
        static const int TYPE_WORD_OPERAND = 11;
        bool hasValidLength(int, string);
};

#endif // OPERANDSIZEVALIDATOR_H
