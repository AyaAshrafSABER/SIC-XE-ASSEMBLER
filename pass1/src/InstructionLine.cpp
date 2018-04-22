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
    defineType();
    extractData();
}

void InstructionLine::defineType() {

    regex instructionTypeRegex(REGEX_COMMENT_ONLY);
    if (regex_match(getInstructionLine(), instructionTypeRegex)) {
        setType(TYPE_COMMENT_ONLY);
        return;
    }

    instructionTypeRegex = regex(REGEX_WITH_LABEL);
    if (regex_match(getInstructionLine(), instructionTypeRegex)) {
        setType(TYPE_WITH_LABEL);
        return;
    }

    instructionTypeRegex = regex(REGEX_WITH_LABEL_WITHOUT_OPERAND);
    if (regex_match(getInstructionLine(), instructionTypeRegex)) {
        setType(TYPE_WITH_LABEL_WITHOUT_OPERAND);
        return;
    }

    instructionTypeRegex = regex(REGEX_WITHOUT_LABEL);
    if (regex_match(getInstructionLine(), instructionTypeRegex)) {
        setType(TYPE_WITHOUT_LABEL);
        return;
    }

    instructionTypeRegex = regex(REGEX_WITHOUT_LABEL_AND_OPERAND);
    if (regex_match(getInstructionLine(), instructionTypeRegex)) {
        setType(TYPE_WITHOUT_LABEL_AND_OPERAND);
        return;
    } else {
        setType(TYPE_ERRONEOUS_LINE);
        return;
    }
}

void InstructionLine::extractData() {

    switch (getType()) {
        case TYPE_WITH_LABEL:
            setLabel(getLabel(getInstructionLine()));
            setOperation(getOperation(getInstructionLine()));
            setOperand(getOperand(getInstructionLine()));
            setComment(getComment(getInstructionLine()));
            setError("No Error");
            break;
        case TYPE_WITH_LABEL_WITHOUT_OPERAND:
            setLabel(getLabel(getInstructionLine()));
            setOperation(getOperation(getInstructionLine()));
            setOperand("");
            setComment(getComment(getInstructionLine()));
            setError("No Error");
            break;
        case TYPE_WITHOUT_LABEL:
            setLabel("");
            setOperation(getOperation(getInstructionLine()));
            setOperand(getOperand(getInstructionLine()));
            setComment(getComment(getInstructionLine()));
            setError("No Error");
            break;
        case TYPE_WITHOUT_LABEL_AND_OPERAND:
            setLabel("");
            setOperation(getOperation(getInstructionLine()));
            setOperand("");
            setComment(getComment(getInstructionLine()));
            setError("No Error");
            break;
        case TYPE_ERRONEOUS_LINE:
            setLabel("");
            setOperation("");
            setOperand("");
            setComment("");
            setError("Invalid instruction line");
            break;
        default:
            break;
    }
}

const string &InstructionLine::getLabel(const string &instructionLine) {
    string label;

    if (!isValidLabel(label)) {
        setType(TYPE_ERRONEOUS_LINE);
        setError("Invalid label.");
    }

    return label;
}

const string &InstructionLine::getOperation(const string &instructionLine) {
    string operation;

    if (!isValidOperation(operation)) {
        setType(TYPE_ERRONEOUS_LINE);
        setError("Invalid operation.");
    }

    return operation;
}

const string &InstructionLine::getOperand(const string &instructionLine) {
    string operand;

    if (!isValidOperand(operand)) {
        setType(TYPE_ERRONEOUS_LINE);
        setError("Invalid operand.");
    }

    return operand;
}

const string &InstructionLine::getComment(const string &instructionLine) {
    string comment;
    return comment;
}

bool InstructionLine::isValidLabel(const string &label) {
    return false;
}

bool InstructionLine::isValidOperation(const string &operation) {
    return false;
}

bool InstructionLine::isValidOperand(const string &operand) {
    return false;
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
}

const string &InstructionLine::getOperation() const {
    return operation;
}

void InstructionLine::setOperation(const string &operation) {
    InstructionLine::operation = operation;
}

const string &InstructionLine::getOperand() const {
    return operand;
}

void InstructionLine::setOperand(const string &operand) {
    InstructionLine::operand = operand;
}

const string &InstructionLine::getComment() const {
    return comment;
}

void InstructionLine::setComment(const string &comment) {
    InstructionLine::comment = comment;
}

const string &InstructionLine::getInstructionLine() const {
    return instructionLine;
}

void InstructionLine::setInstructionLine(const string &instructionLine) {
    InstructionLine::instructionLine = instructionLine;
}

const string &InstructionLine::getError() const {
    return error;
}

void InstructionLine::setError(const string &error) {
    InstructionLine::error = error;
}

InstructionLine::~InstructionLine() = default;
