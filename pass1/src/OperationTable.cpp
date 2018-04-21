#include <iostream>
#include "OperationTable.h"
#define THREE 3
#define ONE 1
#define FOUR 4
#define OPTIONAL 0
#define MUST_EXIST 1
#define NOT_EXIST -1

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

    opName = "SUB";
    info = OperationInformation();
    info.opCode = 0x1C;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "MUL";
    info = OperationInformation();
    info.opCode = 0x20;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
    opTable[opName] = info;

    opName = "DIV";
    info = OperationInformation();
    info.opCode = 0x24;
    info.label = OPTIONAL;
    info.supportedFormats.push_back(THREE);
    info.supportedFormats.push_back(FOUR);
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
}

bool OperationTable::contains(std::string operation) {
    return OperationTable::opTable.find(operation) != OperationTable::opTable.end();
}

OperationInformation OperationTable::getInfo(std::string operation) {
return OperationTable::opTable[operation];
}
void OperationTable::test()
{
   std::cout << "test success!" << std::endl;
}
