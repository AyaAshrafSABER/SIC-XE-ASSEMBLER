//
// Created by Bassam on 4/21/2018.
//

#include "include/InstructionLine.h"
#include <regex>

InstructionLine::InstructionLine(string instructionLine) {
    setInstructionLine(instructionLine);
    parse(instructionLine);
}

void InstructionLine::parse(const string &instructionLine) {
    cmatch matcher;

    regex instructionTypeRegex(REGEX_COMMENT_ONLY);
    if (regex_match(getLine(), instructionTypeRegex)) {
        setType(TYPE_COMMENT_ONLY);
        setProperties("", "", "", getLine());
        return;
    }

    instructionTypeRegex = regex(REGEX_WITH_LABEL);
    if (regex_match(getLine(), instructionTypeRegex)) {
        setType(TYPE_WITH_LABEL);
        regex_search(getLine().c_str(), matcher, instructionTypeRegex);
        setProperties(matcher.str(1), matcher.str(2),
                      matcher.str(3), matcher.str(4));
        return;
    }

    instructionTypeRegex = regex(REGEX_WITH_LABEL_WITHOUT_OPERAND);
    if (regex_match(getLine(), instructionTypeRegex)) {
        setType(TYPE_WITH_LABEL_WITHOUT_OPERAND);
        regex_search(getLine().c_str(), matcher, instructionTypeRegex);
        setProperties(matcher.str(1), matcher.str(2),
                      "", matcher.str(3));
        return;
    }

    instructionTypeRegex = regex(REGEX_WITHOUT_LABEL);
    if (regex_match(getLine(), instructionTypeRegex)) {
        setType(TYPE_WITHOUT_LABEL);
        regex_search(getLine().c_str(), matcher, instructionTypeRegex);
        setProperties("", matcher.str(2),
                      matcher.str(3), matcher.str(4));
        return;
    }

    instructionTypeRegex = regex(REGEX_WITHOUT_LABEL_AND_OPERAND);
    if (regex_match(getLine(), instructionTypeRegex)) {
        setType(TYPE_WITHOUT_LABEL_AND_OPERAND);
        regex_search(getLine().c_str(), matcher, instructionTypeRegex);
        setProperties("", matcher.str(2),
                      "", matcher.str(3));
        return;
    }

    setType(TYPE_ERRONEOUS_LINE);
    setProperties("", "", "", "");
    setError("Invalid instruction line");
}

bool InstructionLine::isValidLabel(const string &label) {
    return true;
}

bool InstructionLine::isValidOperation(const string &operation) {
    return true;
}

bool InstructionLine::isValidOperand(const string &operand) {
    return true;
}

int InstructionLine::getType() const {
    return type;
}

void InstructionLine::setType(int type) {
    InstructionLine::type = type;
}

const string &InstructionLine::getLabel() const {
    return label;
}

void InstructionLine::setLabel(const string &label) {
    InstructionLine::label = label;
    if (!isValidLabel(label)) {
        appendError("Invalid label!");
    }
}

const string &InstructionLine::getOperation() const {
    return operation;
}

void InstructionLine::setOperation(const string &operation) {
    InstructionLine::operation = operation;
    if (!isValidOperation(operation)) {
        appendError("Invalid operation!");
    }
}

const string &InstructionLine::getOperand() const {
    return operand;
}

void InstructionLine::setOperand(const string &operand) {
    InstructionLine::operand = operand;
    if (!isValidOperand(operand)) {
        appendError("Invalid operand!");
    }
}

const string &InstructionLine::getComment() const {
    return comment;
}

void InstructionLine::setComment(const string &comment) {
    InstructionLine::comment = comment;
}

const string &InstructionLine::getLine() const {
    return instructionLine;
}

void InstructionLine::setInstructionLine(const string &instructionLine) {
    InstructionLine::instructionLine = trim(instructionLine);
}

const string &InstructionLine::getError() const {
    return error;
}

void InstructionLine::setError(const string &error) {
    InstructionLine::error = error;
}

string InstructionLine::trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void InstructionLine::setProperties(const string &label, const string &operation, const string &operand,
                                    const string &comment) {
    setLabel(label);
    setOperation(operation);
    setOperand(operand);
    setComment(comment);
}

void InstructionLine::appendError(const string &errorToAppend) {
    this->error.append("\n" + errorToAppend);
}

InstructionLine::~InstructionLine() = default;
