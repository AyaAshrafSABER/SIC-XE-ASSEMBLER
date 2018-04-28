#include <iostream>
#include <OperationTable.h>
#define THREE 3
#define ONE 1
#define TWO 2
#define FOUR 4
#define OPTIONAL 0
#define MUST_EXIST 1
#define NOT_EXIST -1
#include <iostream>
#include <map>
#include <algorithm>

OperationTable *OperationTable::instance = 0;

OperationTable *OperationTable::getInstance() {
    if (instance == 0)
        instance = new OperationTable;
    return instance;
}
OperationTable::OperationTable() {
    initOpTable();
}

void OperationTable::initOpTable() {
    std::string opName;
    OperationInformation info;

    opName = "ADD";
    info = OperationInformation();
    info.opCode = 0x18;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "ADDF";
    info = OperationInformation();
    info.opCode = 0x58;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "ADDR";
    info = OperationInformation();
    info.opCode = 0x90;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "SUB";
    info = OperationInformation();
    info.opCode = 0x1C;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

     opName = "SUBF";
    info = OperationInformation();
    info.opCode = 0x5C;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

     opName = "SUBR";
    info = OperationInformation();
    info.opCode = 0x94;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "MUL";
    info = OperationInformation();
    info.opCode = 0x20;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "MULF";
    info = OperationInformation();
    info.opCode = 0x60;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "MULR";
    info = OperationInformation();
    info.opCode = 0x98;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "DIV";
    info = OperationInformation();
    info.opCode = 0x24;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "DIVF";
    info = OperationInformation();
    info.opCode = 0x64;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "DIVR";
    info = OperationInformation();
    info.opCode = 0x9C;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "AND";
    info = OperationInformation();
    info.opCode = 0x40;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "OR";
    info = OperationInformation();
    info.opCode = 0x44;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "COMP";
    info = OperationInformation();
    info.opCode = 0x28;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "COMPF";
    info = OperationInformation();
    info.opCode = 0x88;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "COMPR";
    info = OperationInformation();
    info.opCode = 0xA0;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "LDA";
    info = OperationInformation();
    info.opCode = 0x00;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "LDCH";
    info = OperationInformation();
    info.opCode = 0x50;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "LDB";
    info = OperationInformation();
    info.opCode = 0x68;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "LDF";
    info = OperationInformation();
    info.opCode = 0x70;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "LDS";
    info = OperationInformation();
    info.opCode = 0x6C;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "LDT";
    info = OperationInformation();
    info.opCode = 0x74;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "LDL";
    info = OperationInformation();
    info.opCode = 0x08;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "LDX";
    info = OperationInformation();
    info.opCode = 0x04;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "TD";
    info = OperationInformation();
    info.opCode = 0xE0;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "RD";
    info = OperationInformation();
    info.opCode = 0xD8;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "WD";
    info = OperationInformation();
    info.opCode = 0xDC;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "TIX";
    info = OperationInformation();
    info.opCode = 0x2C;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STA";
    info = OperationInformation();
    info.opCode = 0x0C;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STCH";
    info = OperationInformation();
    info.opCode = 0x54;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STL";
    info = OperationInformation();
    info.opCode = 0x14;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STX";
    info = OperationInformation();
    info.opCode = 0x10;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "J";
    info = OperationInformation();
    info.opCode = 0x3C;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "JEQ";
    info = OperationInformation();
    info.opCode = 0x30;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "JGT";
    info = OperationInformation();
    info.opCode = 0x34;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "JLT";
    info = OperationInformation();
    info.opCode = 0x38;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "JSUB";
    info = OperationInformation();
    info.opCode = 0x48;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "RSUB";
    info = OperationInformation();
    info.opCode = 0x4C;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    opTable[opName] = info;

    opName = "TIXR";
    info = OperationInformation();
    info.opCode = 0xB8;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "TIO";
    info = OperationInformation();
    info.opCode = 0xF8;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "CLEAR";
    info = OperationInformation();
    info.opCode = 0xB4;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "SVC";
    info = OperationInformation();
    info.opCode = 0xB0;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "FIX";
    info = OperationInformation();
    info.opCode = 0xC4;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    opTable[opName] = info;

    opName = "FLOAT";
    info = OperationInformation();
    info.opCode = 0xC0;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    opTable[opName] = info;

    opName = "HIO";
    info = OperationInformation();
    info.opCode = 0xF4;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    opTable[opName] = info;

    opName = "LPS";
    info = OperationInformation();
    info.opCode = 0xD0;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "NRMO";
    info = OperationInformation();
    info.opCode = 0xC8;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    opTable[opName] = info;

    opName = "RMO";
    info = OperationInformation();
    info.opCode = 0xAC;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "SHIFTL";
    info = OperationInformation();
    info.opCode = 0xA4;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "SHIFTR";
    info = OperationInformation();
    info.opCode = 0xA8;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(TWO);
    opTable[opName] = info;

    opName = "SIO";
    info = OperationInformation();
    info.opCode = 0xF0;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(ONE);
    opTable[opName] = info;

    opName = "SSK";
    info = OperationInformation();
    info.opCode = 0xEC;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STB";
    info = OperationInformation();
    info.opCode = 0x78;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STCH";
    info = OperationInformation();
    info.opCode = 0x54;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STF";
    info = OperationInformation();
    info.opCode = 0x80;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STI";
    info = OperationInformation();
    info.opCode = 0xD4;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STL";
    info = OperationInformation();
    info.opCode = 0x14;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STS";
    info = OperationInformation();
    info.opCode = 0x7C;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STSW";
    info = OperationInformation();
    info.opCode = 0xE8;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STT";
    info = OperationInformation();
    info.opCode = 0x84;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "STX";
    info = OperationInformation();
    info.opCode = 0x10;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

}

bool OperationTable::contains(std::string operation) {
    toUpper(&operation);
    return OperationTable::opTable.find(operation) != OperationTable::opTable.end();
}

void OperationTable::toUpper(string* operation) {
        transform(operation->begin(), operation->end(), operation->begin(), ::toupper);
}

OperationInformation OperationTable::getInfo(std::string operation) {
return OperationTable::opTable[operation];
}
void OperationTable::test()
{
   std::cout << "test success!" << std::endl;
}
