//
// Created by Bassam on 4/21/2018.
//

#include "include/InstructionLine.h"
#include <utility>

InstructionLine::InstructionLine(string instructionLine) {
    setInstructionLine(instructionLine);
    parse(std::move(instructionLine));
}

void InstructionLine::parse(string instructionLine) {

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

InstructionLine::~InstructionLine() = default;
