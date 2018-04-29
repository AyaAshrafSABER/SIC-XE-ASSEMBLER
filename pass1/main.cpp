#include <iostream>
#include <include/InstructionLine.h>

using namespace std;

int main() {
    /*OperationTable  *d;
    OperationTable::getInstance()->test();
     bool ss = OperationTable::getInstance()->contains("ADD");
     //cout << ss;
     ss = OperationTable::getInstance()->contains("ADffD");
     //cout << ss;
     cout << OperationTable::getInstance()->getInfo("ADD").label;
     cout <<  OperationTable::getInstance()->getInfo("MUL").opCode<< std::endl;
     cout <<  OperationTable::getInstance()->getInfo("ADD").supportedFormats[0];*/

    InstructionLine instructionLine = InstructionLine(
            "DONE     END");
    //InstructionLine instructionLine = InstructionLine("           LABEL      LDA       X   ,X             .sadsa             ");
    //InstructionLine instructionLine = InstructionLine("                 LDA       X,X             .sadsa             ");
    //InstructionLine instructionLine = InstructionLine("           LABEL      LDA                               ");
    //InstructionLine instructionLine = InstructionLine("                 LDA                    .sadsa             ");

    cout << instructionLine.getLine() << endl;
    cout << "Type: " << instructionLine.getType() << endl;
    cout << "Error: " << instructionLine.getError() << endl;
    cout << "Label: " << instructionLine.getLabel() << endl;
    cout << "Operation: " << instructionLine.getOperation() << endl;
    cout << "Operand: " << instructionLine.getOperand() << endl;
    cout << "Comment: " << instructionLine.getComment() << endl;


    return 0;
}

