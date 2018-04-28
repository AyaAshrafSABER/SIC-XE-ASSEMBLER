#include "OperandValidator.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <regex>

using namespace std;

int OperandValidator::getOperandType(string operand) {
    using namespace std::regex_constants;
    regex operandTypeRegex(REGEX_IMMEDITAE_WORD);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_IMMEDITAE_WORD;
    }
    operandTypeRegex = regex(REGEX_IMMEDITAE_SYMBOL);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_IMMEDITAE_SYMBOL;
    }

     operandTypeRegex = regex(REGEX_INDIRECT_WORD);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_INDIRECT_WORD;
    }

     operandTypeRegex = regex(REGEX_INDIRECT_SYMBOL);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_INDIRECT_SYMBOL;
    }

    operandTypeRegex = regex(REGEX_HEXA_LITERAL);
    if (regex_match(operand, operandTypeRegex)) {
        if ((operand.length() - 3) %2 == 0) {
            return TYPE_HEXA_LITERAL;
        }
        return -1;
    }

    operandTypeRegex = regex(REGEX_WORD_LITERAL);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_WORD_LITERAL;
    }

     operandTypeRegex = regex(REGEX_BYTE_LITERAL);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_BYTE_LITERAL;
    }
    operandTypeRegex = regex(REGEX_HEXA_OPERAND);
    if (regex_match(operand, operandTypeRegex)) {
        if ((operand.length() - 3) %2 == 0) {
            return TYPE_HEXA_OPERAND;
        }
        return -1;
    }

    operandTypeRegex = regex(REGEX_WORD_OPERAND);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_WORD_OPERAND;
    }

    operandTypeRegex = regex(REGEX_BYTE_OPERAND);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_BYTE_OPERAND;
    }

    operandTypeRegex = regex(REGEX_INDEXED_SYMBOL);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_INDEXED_SYMBOL;
    }

    operandTypeRegex = regex(REGEX_REGISTER_TO_REGISTER, ECMAScript | icase);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_REGISTER_TO_REGISTER;
    }

    operandTypeRegex = regex(REGEX_EXPRESSION);
    if (regex_match(operand, operandTypeRegex)) {
        return TYPE_EXPRESSION;
    }

    if (operand == "*") {
        return TYPE_LOCCTR;
    }
    return -1;
}


bool OperandValidator::isCompatible(int operandType, string opCode, string operand) {
    transform(opCode.begin(), opCode.end(), opCode.begin(), ::toupper);
    if (opCode == "START" && (operandType != 11
            || !isNumberPositive(operand)|| operand.length() > 4)) {
        return false;
    } else if ((opCode == "RESW" || opCode == "RESB")&&
               (operandType != 11 || !isNumberPositive(operand))) {
        return false;
    } else if (opCode == "WORD" && operandType != 11) {
        return false;
    } else if (opCode == "BYTE" && (operandType != 8 && operandType != 9)) {
        return false;
    } else if (opCode == "USE" && operandType != 4) {
        return false;
    } else if ((opCode == "ADDR" || opCode == "SUBR" || opCode == "MULR"
                || opCode == "DIVR" || opCode == "COMPR" || opCode == "RMO")
               && operandType != 12){
        return false;
    } else if ((opCode == "J" || opCode == "JEQ" || opCode == "COMP"
                || opCode == "JLT" || opCode == "JGT" || opCode == "TIX"
                || opCode == "JSUB" || opCode == "RSUB" || opCode == "TD"
                || opCode == "RD" || opCode == "WD")
               && (operandType == 12 || operandType == 8|| operandType == 9)) {
        return false;
    } else if (opCode == "TIXR" && (operandType != 4 || !isRegister(operand))){
        return false;
    } else if (opCode == "ORG" && (operandType != 4 && operandType != 11)) {
        return false;
    } else if (opCode == "EQU" &&
               ((operandType > 4 && operandType < 11)
                  || operandType == 12 || operandType == 13)) {
               return false;
    } else if ((opCode == "J" || opCode == "JEQ" || opCode == "JLT"
               || opCode == "JGT" || opCode == "JSUB" || opCode == "RSUB")
               && (operandType == 5 || operandType == 6 || operandType == 7)){
            return false;
    } else if (opCode == "BASE" && (operand != "*" && operandType != 4
                                    && operandType != 11)) {
        return false;
    } else if (opCode == "END" && operandType != 1 && operandType != 3
               && operandType != 4) {
        return false;
    }

    return true;
}
bool OperandValidator::isNumberPositive(string operand) {
    string positive = "^(\\d)+";
    regex positiveInteger(positive);
    if (regex_match(operand, positiveInteger)) {
        return true;
    }
    return false;
}
bool OperandValidator::isRegister(string operand) {
    using namespace std::regex_constants;
    string reg = "^(A|X|L|B|S|T|F)";
    regex registerOoperand(reg, ECMAScript | icase);
    if (regex_match(operand, registerOoperand)) {
        return true;
    }
    return false;
}

bool OperandValidator::isAbsolute(int operandType) {
    if (operandType == 1 || operandType == 3
        || operandType == 4 || operandType == 10
        || operandType == 12 || operandType == 13
        || operandType == 14) {
        return false;
    }
        return true;

}
bool OperandValidator::isRelative(int operandType) {
if (operandType == 1 || operandType == 3
        || operandType == 4 || operandType == 10
        || operandType == 12 || operandType == 13
        || operandType == 14) {
        return true;
    }
        return false;
}
