//
// Created by Bassam on 4/21/2018.
//

#ifndef PASS_1_INSTRUCTIONLINE_H
#define PASS_1_INSTRUCTIONLINE_H

#include <string>

using namespace std;

class InstructionLine {

public:

    static const int TYPE_ERRONEOUS_LINE = -1;
    static const int TYPE_COMMENT_ONLY = 1;
    static const int TYPE_WITH_LABEL = 2;
    static const int TYPE_WITH_LABEL_WITHOUT_OPERAND = 3;
    static const int TYPE_WITHOUT_LABEL = 4;
    static const int TYPE_WITHOUT_LABEL_AND_OPERAND = 5;
    static const int FORMAT_THREE = 3;
    static const int FORMAT_FOUR = 4;
    static const int OPERAND_TYPE_LITERAL = 0;
    static const int OPERAND_TYPE_NON_LITERAL = 1;

    explicit InstructionLine(string instructionLine);

    ~InstructionLine();

    void parse(const string &instructionLine);

    int getType() const;

    const string &getLabel() const;

    const string &getOperation() const;

    const string &getOperand() const;

    const string &getComment() const;

    const string &getLine() const;

    const string &getError() const;

    int getInstructionFormatType() const;

    int getOperandType() const;

private:

    const string REGEX_COMMENT_LINE = "\\.(\\w*\\s*)*";
    const string REGEX_LABEL = "^(\\s*[a-zA-Z][\\w$]+)";
    const string REGEX_OPERATION = "([+]{0,1}[a-zA-Z]{3,5})";
    const string REGEX_OPERAND = "([=]{0,1}[\\w,+\\-*/%'$]*)";

    const string REGEX_COMMENT_ONLY = "^" + REGEX_COMMENT_LINE + "$";

    const string REGEX_WITH_LABEL = REGEX_LABEL + "\\s+" +
                                    REGEX_OPERATION + "\\s+" +
                                    REGEX_OPERAND + "\\s*" +
                                    "(" + REGEX_COMMENT_LINE + "$){0,1}";

    const string REGEX_WITH_LABEL_WITHOUT_OPERAND = REGEX_LABEL + "\\s+" +
                                                    REGEX_OPERATION + "\\s*" +
                                                    "(" + REGEX_COMMENT_LINE + "$){0,1}";

    const string REGEX_WITHOUT_LABEL = "^(\\s*" + REGEX_OPERATION + ")" + "\\s+" +
                                       REGEX_OPERAND + "\\s*" +
                                       "(" + REGEX_COMMENT_LINE + "$){0,1}";

    const string REGEX_WITHOUT_LABEL_AND_OPERAND = "^(\\s*" + REGEX_OPERATION + ")" + "\\s*" +
                                                   "(" + REGEX_COMMENT_LINE + "$){0,1}";

    int type;
    int instructionFormatType;
    int operandType;
    string label;
    string operation;
    string operand;
    string comment;
    string instructionLine;
    string error;

    void setInstructionLine(const string &instructionLine);

    void setComment(const string &comment);

    void setOperand(const string &operand);

    void setOperation(const string &operation);

    void setLabel(const string &label);

    void setType(int type);

    void setError(const string &error);

    void setInstructionFormatType(int instructionFormatType);

    void setOperandType(int operandType);

    bool isValidLabel(const string &label);

    bool isValidOperation(const string &operation);

    bool isValidOperand(const string &operand);

    string trim(const string &str);

    void setProperties(const string &label, const string &operation, const string &operand, const string &comment);

    void appendError(const string &errorToAppend);
};


#endif //PASS_1_INSTRUCTIONLINE_H
