#include <iostream>
#include <string.h>
#include "OperationTable.h"
using namespace std;

int main()
{
    OperationTable  *d;
    OperationTable::getInstance()->test();
     bool ss = OperationTable::getInstance()->contains("ADD");
     //cout << ss;
     ss = OperationTable::getInstance()->contains("ADffD");
     //cout << ss;
     cout << OperationTable::getInstance()->getInfo("ADD").label;
     cout <<  OperationTable::getInstance()->getInfo("MUL").opCode<< std::endl;
     cout <<  OperationTable::getInstance()->getInfo("ADD").supportedFormats[0];

    return 0;
}

