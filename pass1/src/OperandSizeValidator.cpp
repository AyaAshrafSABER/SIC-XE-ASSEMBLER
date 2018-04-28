#include "OperandSizeValidator.h"
using namespace std;

bool OperandSizeValidator::hasValidLength(int operandType, string operand) {
    if (operandType == TYPE_BYTE_OPERAND) {
        if ((operand.length() - 3) <= 15){
            return true;
        }
    } else if (operandType == TYPE_HEXA_OPERAND) {
        if ((operand.length() - 3) <= 14){
            return true;
        }
    } else if (operandType == TYPE_WORD_OPERAND) {
        int operandIntegerValue = atoi(operand.c_str());
        if ((operandIntegerValue > 0 && operand.length() <= 4)
            || (operandIntegerValue < 0 && operand.length() <= 5)) {
            return true;
        }
    }
    return false;
}
