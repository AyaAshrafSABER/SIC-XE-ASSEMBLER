//
// Created by Bassam on 4/21/2018.
//

#ifndef PASS_1_INSTRUCTIONLINE_H
#define PASS_1_INSTRUCTIONLINE_H

#include <string>

using namespace std;

class InstructionLine {

public:
    static const int TYPE_COMMENT = 0;
    static const int TYPE_WITH_LABEL = 1;
    static const int TYPE_WITH_LABEL_AND_COMMENT = 2;
    static const int TYPE_WITHOUT_LABEL = 3;
    static const int TYPE_WITHOUT_LABEL_AND_COMMENT = 4;

    explicit InstructionLine(string instructionLine);

    ~InstructionLine();

    void parse(string instructionLine);

    int getType() const;

    void setType(int type);

    const string &getLabel() const;

    void setLabel(const string &label);

    const string &getOperation() const;

    void setOperation(const string &operation);

    const string &getOperand() const;

    void setOperand(const string &operand);

    const string &getComment() const;

    void setComment(const string &comment);

    const string &getInstructionLine() const;

private:
    const string REGEX_COMMENT_LINE = ".(\\w*\\s*)*";
    const string REGEX_COMMENT_LINE_ONLY = "^" + REGEX_COMMENT_LINE + "$";
    const string REGEX_LABEL = "^(\\s*\\w+)";
    const string REGEX_OPERATION = "[a-zA-Z]{3,5}";
    const string REGEX_OPERAND = "\\w*";
    const string REGEX_INSTRUCTION_WITH_LABEL = REGEX_LABEL + "\\s+" +
                                                REGEX_OPERATION + "\\s+" +
                                                REGEX_OPERAND + "\\s+" +
                                                "(" + REGEX_COMMENT_LINE + "){0,1}" + "$";
    const string REGEX_INSTRUCTION_WITHOUT_LABEL = "^(\\s*" + REGEX_OPERATION + ")" + "\\s+" +
                                                   REGEX_OPERAND + "\\s+" +
                                                   "(" + REGEX_COMMENT_LINE + "){0,1}" + "$";

    int type;
    string label;
    string operation;
    string operand;
    string comment;
    string instructionLine;

    void setInstructionLine(const string &instructionLine);
};


#endif //PASS_1_INSTRUCTIONLINE_H
