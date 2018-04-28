#include "Controller.h"
#include <iostream>
#include <inOutFile.h>
#include <InstructionLine.h>
#include <OperationTable.h>
#include <DirectiveTable.h>
#include <vector>
#include <OperandValidator.h>
#include <SymbolTable.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;



Controller::Controller()
{

}
void Controller :: start()
{
    int locctr;
    LitTable litTab = LitTable();
    inOutFile file = inOutFile();
    std::vector<std::string> input = file.readFile("Reader.txt");
    std::vector<std::string> intermediateFile;
    OperandValidator opValid = OperandValidator();
    DirectiveTable dirs;
    dirs.getInstance();
    OperationTable opTable;
    opTable.getInstance();
    SymbolTable symTab;

    /**/
    int startingAdrr = 0;
    string errorMessage;
    int fileIterator = 0;
    InstructionLine instruction = InstructionLine(input[fileIterator]);
    string label = instruction.getLabel();
    string operand = instruction.getOperand();
    string operation = instruction.getOperation();
    string line = instruction.getLine();
    int type = instruction.getType();
    bool startFlag = false;
    if(operation == "start"){
        locctr = atoi(operand.c_str());
        startingAdrr = locctr;
        startFlag = true;
        intermediateFile.push_back(line);
        cout<<line << endl;
    }
    if(!startFlag){
        locctr = 0;
    } else{
        fileIterator = 1;
        InstructionLine ins = InstructionLine(input[fileIterator]);
        label = ins.getLabel();
        operand = ins.getOperand();
        operation = ins.getOperation();
        line = ins.getLine();
        type = ins.getType();
    }
    while(operation != "end"  ){  ///or end of file
        if(type != TYPE_COMMENT_ONLY){
            if((operation == "nobase" || operation == "ltorg")
                && type != TYPE_WITHOUT_LABEL_AND_OPERAND && type != TYPE_WITH_LABEL_WITHOUT_OPERAND){
                errorMessage = "error in operand";
                continue;
            }
            int operandType;
            if (type == TYPE_WITH_LABEL || type == TYPE_WITHOUT_LABEL) {
                operandType = opValid.getOperandType(operand);
                if (!opValid.isCompatible(operandType, operation, operand)) {
                    errorMessage = "error in operand";
                    continue;
                }
                if (operandType == TYPE_HEXA_LITERAL ||
                    operandType == TYPE_BYTE_LITERAL ||
                    operandType == TYPE_WORD_LITERAL) {
                    if(!litTab.contain(operand)){
                        litTab.addLiteral(operand, operandType);
                    }
                }
            }
            if(type == TYPE_WITH_LABEL || type == TYPE_WITH_LABEL_WITHOUT_OPERAND){

                if(symTab.containSymbol(&label)){
                    errorMessage = "Symbol already found";
                } else{
                    symTab.addSymbol(&label, locctr, operation == "equ");
                }
            }
            if(opTable.contains(operation)){
                //inc locctr
            } else if (!dirs.contains(operation)) {
                errorMessage = "Opcode doesn't exist";
            }

            if(operation == "word"){
                locctr += 3;
            } else if(operation == "resw"){
                locctr += 3 * atoi(operand.c_str());
            } else if(operation == "resb"){
                locctr += atoi(operand.c_str());
            } else if(operation == "byte"){
                if (operandType == TYPE_HEXA_OPERAND) {
                    locctr += (operand.length() - 3)/2;
                } else if (operandType == TYPE_BYTE_OPERAND) {
                    locctr += (operand.length() - 3);
                }
            } else if (operation == "org") {
                if (operandType == TYPE_SYMBOL_OPERAND
                    && !symTab.containSymbol(&operand)) {
                        errorMessage("error in operand");
                } else {
                    locctr = symTab.getSymbolAddress(&operand);
                }
            } else if (operation == "equ") {
                if ((operandType == TYPE_IMMEDITAE_SYMBOL
                    || operandType == TYPE_INDIRECT_SYMBOL
                    || operandType == TYPE_SYMBOL_OPERAND)
                    && !symTab.containSymbol(&operand)) {
                        errorMessage("error in operand");
                } else if (operandType == TYPE_EXPRESSION){
                    string symbolFromExp = getSymbol(operand);
                    if (!symTab.containSymbol(&symbolFromExp)) {
                        errorMessage("error in operand");
                    }
                }
            } else if (operation == "ltorg") {
                litTab.assignAddress(locctr);
            } else if (operation == "base") {
                baseFound = true;
            }  else if (operation == "ldb") {
                endBaseFound = true;
            }
        }

        //handle if endBase = false; then error in line of base or load base
        intermediateFile.push_back(line);
        cout<<line << endl;
        fileIterator ++;
        InstructionLine instruct = InstructionLine(input[fileIterator]);
        label = instruct.getLabel();
        operand = instruct.getOperand();
        operation = instruct.getOperation();
        line = instruct.getLine();
        type = instruct.getType();
    }


    if (operation == "end") {
        if (baseFound && !baseFound) {
            errorMessage("Base register is not identified");
        }
        if (type == TYPE_WITH_LABEL || type == TYPE_WITH_LABEL_WITHOUT_OPERAND) {
            if (symTab.containSymbol(&label)) {
                symTab.addSymbol(&label, locctr, false);
            } else {
                errorMessage("duplicate symbol");
            }
        }
        if (type == TYPE_WITH_LABEL || type == TYPE_WITHOUT_LABEL) {
            int operandType = opValid.getOperandType(operand);
            if(!opValid.isCompatible(operandType, operation, operand)) {
              errorMessage("error in operand");
            }
        }
    }
    ///set end address by symtab.getAddress(operand);
    intermediateFile.push_back(line);
    cout<<line << endl;
    intermediateFile.push_back(static_cast<ostringstream*>( &(ostringstream() << locctr - startingAdrr) )->str());
    cout<<locctr - startingAdrr << endl;

}

string Controller::getSymbol(string expression) {
    std::size_t pos = expression.find("+");
    std::string symbolInExpression = expression.substr(0,pos);

    if (expression == symbolInExpression) {
        pos = expression.find("-");
        symbolInExpression = expression.substr(0,pos);
    }
    return symbolInExpression;
}
